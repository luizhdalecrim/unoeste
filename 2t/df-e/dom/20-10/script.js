function pegaValor()
 {
    document.getElementById("nome").value += ' Infoeste 2026'
    alert(document.getElementById("nome").value);
    mudaImg();
 }

 function teste()    {
    var elemento=document.getElementById("intro");
    elemento.align="center";
    elemento.innerHTML="<strong style='color:blue;'>teste modificado</strong>"; 

    // vai pegar todos os elementos <p> e colocar no vetor
    var vetP=document.getElementsByTagName('p');
    alert(vetP.length);

    // quero pegar apenas os <p> que estão dentro do <div id="main">
    var vDiv = document.getElementById('main');
    // aqui pega só os elementos <p> dentro da <div>
    var vetPDiv = vDiv.getElementsByTagName('p'); 
    for (let i=0; i<vetPDiv.length; i++){
        vetPDiv[i].align = 'center';
        vetPDiv[i].innerHTML += ' alterado!!'; 
    }
} 

function mudaImg()
 {
	//document.getElementById("image").src="logo-fipp.png";
    // a variável recebeu o objeto <img> inteiro
    var vImg = document.getElementById("image"); 
    //alert(vImg.src)
    if (vImg.src.indexOf("logo-fipp.png")!=-1){ // achou o nome do arquivo na string
        vImg.src = 'logoUnoeste.png';
        vImg.height = 150;
        vImg.width = 250;
    }
    else{
      vImg.src = "logo-fipp.png"; 
      vImg.height = 120;
      vImg.width = 200;
    }

 }

function sugereNome(){ 
    var pessoas = ["João", "José", "Maria", "Sebastião", "Ana"];
    var vetP = document.querySelectorAll("p");
    
    for (let i=0; i<vetP.length; i++)
      vetP[i].textContent=pessoas[(Math.floor(Math.random()*pessoas.length))]; 
}

// esta função fica genérica, ou seja, funciona por qualquer objeto que tenha a propriedade de texto
function changetext(id)
  {
    id.innerHTML="Ooops!";
  }

  function mOver(obj)
      {  document.body.style.backgroundColor="red"; 
         document.body.style.color="white";
         obj.innerHTML="fundo vermelho e caracteres em branco";
      }
      function mOut(obj)
      {  document.body.style.backgroundColor="yellow"; 
         document.body.style.color="blue";
         obj.innerHTML="fundo amarelo e caracteres azuis";
      }



 
