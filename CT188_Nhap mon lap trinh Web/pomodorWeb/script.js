var hours = document.getElementById("hours");
var minutes = document.getElementById("minutes");
var seconds = document.getElementById("seconds");
var totalSeconds = 0;
var btnStart = document.getElementsByClassName("btn start")[0];
var btnPause = document.getElementsByClassName("btn pause")[0];
var btnStop = document.getElementsByClassName("btn stop")[0];
var btnReset = document.getElementsByClassName("btn reset")[0];
var btn = [btnStart,btnPause,btnStop,btnReset];


btnStart.onclick = function (){
    var myStart = setInterval(fStart, 1000);
    btnStart.disabled=true;

    btnPause.onclick = function (){
        clearInterval(myStart);
        btnStart.value="Cont";
        btnStart.disabled=false;
    }

    btnStop.onclick = function (){
        btnStart.value="Start";
        clearInterval(myStart);
        btnStart.disabled=true;
        btnPause.disabled=true;
    }

    btnReset.onclick = function (){
        btnStart.value="Start";
        clearInterval(myStart);
        btnStart.disabled=false;
        btnPause.disabled=false;
        fReset();
    }

    
}


function fReset(){
    hours.innerHTML = "00";
    minutes.innerHTML = "00";
    seconds.innerHTML = "00";
    totalSeconds = 0;
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