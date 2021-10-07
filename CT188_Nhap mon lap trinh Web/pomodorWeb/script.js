var hours = document.getElementById("hours");
var minutes = document.getElementById("minutes");
var seconds = document.getElementById("seconds");
var totalSeconds = 0;
var myStart;
var btnStart = document.getElementsByClassName("btn start")[0];
var btnPause = document.getElementsByClassName("btn pause")[0];
var btnStop = document.getElementsByClassName("btn stop")[0];
var btnReset = document.getElementsByClassName("btn reset")[0];
var clickedStart = false, clickedPause = false;
var audioPlayer = document.getElementById("audioPlayer");
var audioVolume = document.getElementById("audioVolume");
window.onload = main;
function main(){
    btnStart.onclick = runStart;
    btnPause.onclick = runPause;
    btnStop.onclick  = runStop;
    btnReset.onclick = runReset;
    audioVolume.oninput = runVolume;
}

function runVolume(){
    audioPlayer.volume = (audioVolume.value/100);
    var titleVolume = document.getElementsByClassName("titleVolume")[0];
    titleVolume.innerHTML = audioVolume.value +"%";
}

function runStart(){
    myStart = setInterval(fStart, 1000);
    btnStart.disabled=true;
    clickedStart = true;
    audioPlayer.play();
}

function runPause(){
    if(clickedStart == true){
        clearInterval(myStart);
        btnStart.value="Cont";
        btnStart.disabled=false;
        clickedPause = true;
        audioPlayer.pause();
    }
}

function runStop(){
    if(clickedStart == true || clickedPause == true){
        btnStart.value="Start";
        clearInterval(myStart);
        btnStart.disabled=true;
        btnPause.disabled=true;
        audioPlayer.pause();
    }
}

function runReset(){
        btnStart.value="Start";
        clearInterval(myStart);
        btnStart.disabled=false;
        btnPause.disabled=false;
        clickedStart = false;
        clickedPause = false;
        fReset();
        audioPlayer.pause();
}   

function fStart(){
    ++totalSeconds;
    seconds.innerHTML = pad(totalSeconds%60);
    minutes.innerHTML = pad(parseInt(totalSeconds/60));
    hours.innerHTML   = pad(parseInt(totalSeconds/3600));
}

function pad(val){
    var valString = val + "";
    if(valString.length<2){
        return "0" + valString;
    }else{
        return valString;
    }
}

function fReset(){
    hours.innerHTML = "00";
    minutes.innerHTML = "00";
    seconds.innerHTML = "00";
    totalSeconds = 0;
}

