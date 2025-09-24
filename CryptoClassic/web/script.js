// script.js
function normalize(s){
  return s.replace(/[^a-zA-Z]/g,'').toUpperCase();
}

document.querySelectorAll('.tabs button').forEach(b=>{
  b.addEventListener('click', ()=> {
    document.querySelectorAll('.tabs button').forEach(x=>x.classList.remove('active'));
    b.classList.add('active');
    document.querySelectorAll('.tab').forEach(t=>t.classList.remove('active'));
    document.getElementById(b.dataset.tab).classList.add('active');
  });
});

/* Caesar */
function caesarEncrypt(){
  let p = normalize(document.getElementById('c_plain').value);
  let k = parseInt(document.getElementById('c_k').value) || 0;
  let out = '';
  for(let c of p) out += String.fromCharCode((c.charCodeAt(0)-65 + k)%26 + 65);
  document.getElementById('c_out').value = out;
}
function caesarDecrypt(){
  let c = normalize(document.getElementById('c_plain').value);
  let k = parseInt(document.getElementById('c_k').value) || 0;
  let out = '';
  for(let ch of c) out += String.fromCharCode((ch.charCodeAt(0)-65 - k +26)%26 + 65);
  document.getElementById('c_out').value = out;
}

/* Affine */
function modInv(a,m){
  a = ((a % m)+m)%m;
  for(let x=1;x<m;x++) if((a*x)%m === 1) return x;
  return -1;
}
function affineEncrypt(){
  let p = normalize(document.getElementById('a_plain').value);
  let a = parseInt(document.getElementById('a_a').value)||1;
  let b = parseInt(document.getElementById('a_b').value)||0;
  let out = '';
  for(let ch of p) out += String.fromCharCode(( (a*(ch.charCodeAt(0)-65) + b) %26 ) +65);
  document.getElementById('a_out').value = out;
}
function affineDecrypt(){
  let c = normalize(document.getElementById('a_plain').value);
  let a = parseInt(document.getElementById('a_a').value)||1;
  let b = parseInt(document.getElementById('a_b').value)||0;
  let inv = modInv(a,26);
  if(inv === -1){ alert('a không có nghịch đảo modulo 26'); return; }
  let out = '';
  for(let ch of c) out += String.fromCharCode(( (inv * ((ch.charCodeAt(0)-65 - b + 26)) )%26 ) +65);
  document.getElementById('a_out').value = out;
}

/* Columnar Transposition */
function transEncrypt(){
  let p = normalize(document.getElementById('t_plain').value);
  let key = document.getElementById('t_key').value;
  if(!key) { alert('Nhập key'); return; }
  let cols = key.length;
  while(p.length % cols) p += 'X';
  let rows = p.length / cols;
  let mat = [];
  for(let r=0;r<rows;r++) mat.push(p.slice(r*cols, r*cols+cols));
  let order = key.split('').map((ch,i)=>({ch,i})).sort((a,b)=>a.ch.localeCompare(b.ch));
  let out = '';
  for(let o of order){
    for(let r=0;r<rows;r++) out += mat[r][o.i];
  }
  document.getElementById('t_out').value = out;
}
function transDecrypt(){
  let c = normalize(document.getElementById('t_plain').value);
  let key = document.getElementById('t_key').value;
  if(!key){ alert('Nhập key'); return; }
  let cols = key.length;
  let rows = c.length / cols;
  let order = key.split('').map((ch,i)=>({ch,i})).sort((a,b)=>a.ch.localeCompare(b.ch));
  let mat = Array.from({length:rows}, ()=>Array(cols).fill(''));
  let idx = 0;
  for(let o of order){
    for(let r=0;r<rows;r++){
      mat[r][o.i] = c[idx++];
    }
  }
  let out = '';
  for(let r=0;r<rows;r++) for(let j=0;j<cols;j++) out += mat[r][j];
  document.getElementById('t_out').value = out;
}

/* Vigenere */
function vigEncrypt(){
  let p = normalize(document.getElementById('v_plain').value);
  let key = normalize(document.getElementById('v_key').value);
  if(!key){ alert('Nhập key'); return; }
  let out = '';
  for(let i=0;i<p.length;i++){
    let k = key[i % key.length].charCodeAt(0) - 65;
    out += String.fromCharCode((p[i].charCodeAt(0)-65 + k)%26 + 65);
  }
  document.getElementById('v_out').value = out;
}
function vigDecrypt(){
  let c = normalize(document.getElementById('v_plain').value);
  let key = normalize(document.getElementById('v_key').value);
  if(!key){ alert('Nhập key'); return; }
  let out = '';
  for(let i=0;i<c.length;i++){
    let k = key[i % key.length].charCodeAt(0) - 65;
    out += String.fromCharCode((c[i].charCodeAt(0)-65 - k + 26)%26 + 65);
  }
  document.getElementById('v_out').value = out;
}

/* Playfair */
function buildSquare(key){
  key = key.replace(/[^a-zA-Z]/g,'').toUpperCase().replace(/J/g,'I');
  let used = {};
  used['J'] = true;
  let seq = '';
  for(let ch of key) if(!used[ch]){ seq += ch; used[ch]=true; }
  for(let c=65;c<=90;c++){
    let ch = String.fromCharCode(c);
    if(!used[ch]) seq += ch;
  }
  let sq = [];
  for(let i=0;i<5;i++) sq.push(seq.slice(i*5, i*5+5).split(''));
  return sq;
}
function findPos(sq,ch){
  for(let i=0;i<5;i++) for(let j=0;j<5;j++) if(sq[i][j]===ch) return [i,j];
  return [-1,-1];
}
function prepDigraphs(plain){
  plain = plain.replace(/[^a-zA-Z]/g,'').toUpperCase().replace(/J/g,'I');
  let out = '';
  for(let i=0;i<plain.length;){
    let a = plain[i];
    let b = (i+1<plain.length) ? plain[i+1] : 'X';
    if(a===b){
      out += a + 'X';
      i++;
    } else {
      out += a + b;
      i+=2;
    }
  }
  if(out.length%2) out += 'X';
  return out;
}
function playEncrypt(){
  let p = document.getElementById('p_plain').value;
  let key = document.getElementById('p_key').value;
  if(!key){ alert('Nhập keyword'); return; }
  let sq = buildSquare(key);
  let dig = prepDigraphs(p);
  let out = '';
  for(let i=0;i<dig.length;i+=2){
    let a = findPos(sq,dig[i]), b = findPos(sq,dig[i+1]);
    if(a[0]===b[0]){ // same row
      out += sq[a[0]][(a[1]+1)%5];
      out += sq[b[0]][(b[1]+1)%5];
    } else if(a[1]===b[1]){ // same col
      out += sq[(a[0]+1)%5][a[1]];
      out += sq[(b[0]+1)%5][b[1]];
    } else {
      out += sq[a[0]][b[1]];
      out += sq[b[0]][a[1]];
    }
  }
  document.getElementById('p_out').value = out;
}
function playDecrypt(){
  let c = document.getElementById('p_plain').value.replace(/[^a-zA-Z]/g,'').toUpperCase();
  let key = document.getElementById('p_key').value;
  if(!key){ alert('Nhập keyword'); return; }
  let sq = buildSquare(key);
  let out = '';
  for(let i=0;i<c.length;i+=2){
    let a = findPos(sq,c[i]), b = findPos(sq,c[i+1]);
    if(a[0]===b[0]){
      out += sq[a[0]][(a[1]+4)%5];
      out += sq[b[0]][(b[1]+4)%5];
    } else if(a[1]===b[1]){
      out += sq[(a[0]+4)%5][a[1]];
      out += sq[(b[0]+4)%5][b[1]];
    } else {
      out += sq[a[0]][b[1]];
      out += sq[b[0]][a[1]];
    }
  }
  document.getElementById('p_out').value = out;
}
