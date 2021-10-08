window.onload = main;
function main(){
    var submit = document.getElementById('sub');
    var reset = document.getElementById('reset');
    submit.onclick = output;
    reset.onclick = clear;
}

function output(){
    var fname = document.getElementsByName('txtFirstName')[0].value;
    var lname = document.getElementsByName('txtLastName')[0].value;
    var valCompany = document.getElementsByName('txtCompany')[0].value;
    var valPhone = document.getElementsByName('txtPhone')[0].value;
    var valEmail = document.getElementsByName('txtEmail')[0].value;
    var valAddress = document.getElementsByName('txtAddress')[0].value;
    var valdob = document.getElementById('txtdob').value.toString();

    sumString('name', 'Name: '+fname+' '+lname);
    sumString('company', 'Company: '+ valCompany);
    sumString('phone', 'Phone: '+ valPhone);
    sumString('email', 'Email: '+ valEmail);
    sumString('address', 'Address: '+ valAddress);
    sumString('dob', 'Day of birth: '+ valdob);

}

function clear(){
    sumString('name', 'Name:');
    sumString('company', 'Company:');
    sumString('phone','Phone:');
    sumString('email', 'Email:');
    sumString('address', 'Address:');
    sumString('dob', 'Day of birth:');
}

function sumString(className, Val){
    document.getElementsByClassName(className)[0].innerHTML= Val;
}

function isNum(event){
    var key = event.which || event.keyCode;
    if (key < 48 || key > 57 ){
        return false;
    }
    return true;
}
