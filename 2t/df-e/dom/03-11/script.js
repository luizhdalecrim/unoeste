/*FORMA 3 - que ocorre antes de finalizar o carregamento da página e o elemento ser exibido para o usuário*/
document.addEventListener('DOMContentLoaded', function () {
    let vetLinks = document.querySelectorAll('a');
    for (let i = 0; i < vetLinks.length; i++) {
        vetLinks[i].addEventListener('click', mensagem2, false);
    }
}, false)

function criarconta() {
    var login = document.querySelector("#tx_login");
    var senha = document.querySelector("#tx_senha");
    var confsenha = document.querySelector("#tx_confsenha");

    login.style.border = "solid 1px black";
    login.setAttribute('placeholder', '');
    senha.style.border = "solid 1px black";
    senha.setAttribute('placeholder', '');
    var correto = true;
    if (login.value.length < 8) {
        login.value = "";
        login.setAttribute('placeholder', 'Preencha corretamente!');
        login.style.border = "solid 2px red";
        correto = false;
    }
    //var atpos = email.value.indexOf("@");
    //var dotpos = email.value.lastIndexOf(".");
    //if (atpos < 1 || dotpos < atpos + 2 || dotpos + 2 >= email.length) {
    var regEx = new RegExp(/^(\w+[\-\.])*\w+@(\w+\.)+[A-Za-z]+$/);
    if (!regEx.test(senha.value)) {
        senha.value = "";
        senha.setAttribute('placeholder', 'Preencha corretamente!');
        senha.style.border = "solid 2px red";
        correto = false;
    }
    // return correto;
    if (correto) {
        alert(login.value + ' usuário criado!')
        login.value = '';
        senha.value = '';
    }
    else
        alert('Verifique seus dados...');
}

/*FORMA 1 - para associar eventos em tempo de execução a um elemento HTML, a busca pelo elemento deve estar após a criação dele na parte do <body>, então código fonte do Javascript deve estar após a seção <body> */
var parag = document.querySelector('#frase');
parag.onclick = mensagem;

/*FORMA 2 - aqui o evento será associado usando o método addEventListener, o funcionamento será similar ao da FORMA 1*/
var parag2 = document.querySelector('#frase2');
parag2.addEventListener('click', mensagem, false);

//Usando a FORMA 2
var divCur = document.querySelector('#divCursos');
var vetH3 = divCur.querySelectorAll('h3');
for (let i = 0; i < vetH3.length; i++)
    vetH3[i].addEventListener('click', mensagem, false);

var vetH4 = divCur.querySelectorAll('h4');
for (let i = 0; i < vetH4.length; i++)
    vetH4[i].addEventListener('click', function () {
        vetH4[i].textContent = '<h4> alterado!!'
    }, false)