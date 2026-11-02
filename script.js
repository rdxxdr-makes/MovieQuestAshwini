const movies=[["Warrior's Path","Action","Hindi",8.1],["Sky Mission","Action","English",7.8],["Laugh Out Loud","Comedy","Hindi",8.0],["Funny Days","Comedy","English",7.5],["The Last Letter","Drama","Hindi",8.4],["Life's Journey","Drama","English",8.2],["Magic Planet","Animation","English",8.6],["Little Heroes","Animation","Hindi",7.9],["Future World","Science Fiction","English",8.7],["Beyond Earth","Science Fiction","Hindi",8.0]];
const genres=["Action","Comedy","Drama","Animation","Science Fiction"];
const screen=document.getElementById("screen"),box=document.getElementById("choices");
const menu='<span class="h">===== MOVIE RECOMMENDATION QUEST =====</span>\n'+genres.map((g,i)=>`${i+1}. ${g}`).join("\n")+"\n6. Exit\nEnter your choice: ";
function esc(s){return s.replace(/&/g,"&amp;").replace(/</g,"&lt;")}
function show(html){screen.innerHTML=html;screen.scrollTop=screen.scrollHeight}
function pick(n){
  let out=menu+`<span class="u">${n}</span>\n`;
  if(n===6){show(out+"Thank you for using Movie Recommendation Quest!");return}
  const g=genres[n-1];out+='\n<span class="h">--- Recommended Movies ---</span>\n';
  movies.filter(m=>m[1]===g).forEach(m=>{out+=`\nMovie: ${esc(m[0])}\nGenre: ${m[1]}\nLanguage: ${m[2]}\nRating: ${m[3].toFixed(1)}/10\n`});
  show(out)}
[...genres,"Exit"].forEach((g,i)=>{const b=document.createElement("button");b.textContent=`${i+1} ${g}`;b.onclick=()=>pick(i+1);box.appendChild(b)});
show(menu);
const cp=document.getElementById("copy");
cp.onclick=()=>{navigator.clipboard.writeText(document.getElementById("code").textContent).then(()=>{cp.textContent="Copied";setTimeout(()=>cp.textContent="Copy code",1500)})};
