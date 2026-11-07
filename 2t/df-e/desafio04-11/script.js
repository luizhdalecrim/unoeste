function enviar() {
    var razsocial = document.getElementById("inrazsocial");
    var nomefanta = document.getElementById("innomefanta");
    var email = document.getElementById("inemail");
    var cnpj = document.getElementById("incnpj");
    var tel = document.getElementById("intel");
    var datinauguracao = document.getElementById("indatinauguracao");
    var senha = document.getElementById("insenha");
    var confSenha = document.getElementById("inconfsenha");
    var valido = false;


    var reraznome = new RegExp(/^[a-zA-Z]\s[a-zA-Z]$/);
    var validarazsocial = reraznome.test(razsocial.value);
    if (!validarazsocial) {
        razsocial.value = "";
        razsocial.setAttribute('placeholder', 'Preencha a razão social corretamente!');
        razsocial.style.border = "solid 2px red";
    }
    else {
        valido = true;
    }

    var validanomefanta = reraznome.test(nomefanta.value);
    if (!validanomefanta) {
        nomefanta.value = "";
        nomefanta.setAttribute('placeholder', 'Preencha o nome fantasia corretamente!');
        nomefanta.style.border = "solid 2px red";
    }
    else {
        valido = true;
    }
    var reemail = new RegExp(/^[\w-\.]+@([\w-]+\.)+[\w-]{2,4}$/);
    var validaemail = reemail.test(email.value);
    if (!validaemail) {
        email.value = "";
        email.setAttribute('placeholder', 'Preencha o email corretamente!');
        email.style.border = "solid 2px red";
    }
    else {
        valido = true;
    }
    var recnpj = new RegExp(/^\d{2}\.\d{3}\.\d{3}\/\d{4}\-\d{2}$/);
    var validacnpj = recnpj.test(cnpj.value);
    if (!validacnpj) {
        cnpj.value = "";
        cnpj.setAttribute('placeholder', 'CNPJ inválido!');
        cnpj.style.border = "solid 2px red";
    }
    else {
        valido = true;
    }

    var retel = new RegExp(/^\(\d{2}\)\s\d{5}\-\d{4}$/);
    var validatel = retel.test(tel.value);
    if (!validatel) {
        tel.value = "";
        tel.setAttribute('placeholder', 'Insira o telefone corretamente!');
        tel.style.border = "solid 2px red";
    }
    else {
        valido = true;
    }
    var resenha = /^[0-9]+$/;

    if (!resenha.test(senha.value)) {
        senha.value = "";
        senha.setAttribute('placeholder', 'Insira o telefone corretamente!');
        senha.style.border = "solid 2px red";
        correto = false;
    }

    if (senha.value != confSenha.value || confSenha.value == '') {
        confSenha.value = "";
        confSenha.setAttribute('placeholder', 'Insira o telefone corretamente!');
        confSenha.style.border = "solid 2px red";
        correto = false;
    }

    if (correto == true) {
        alert("Cadastro concluído!!");
    }
    else {
        alert("Ocorreu um erro!!");
    }
}
