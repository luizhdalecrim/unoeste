/*
    Criar uma estrutura de dados para deixar algumas informações pré-carregadas 
com o intuito de aparecer na tabela quando a página for carregada. Esses dados 
irão representar um dataset que a interface (front-end) vai receber de uma classe 
de persistência (banco de dados), é assim que normalmente acontece no ambiente de 
produção "profissional", onde a interface recebe os dados de forma genérica 
(JSON, XML, CSV, etc.)
*/

var vetAlunos = [
    {ra:123, nome:'Jairo', curso:'ADS'},
    {ra:456, nome:'James', curso:'ADS'},
    {ra:789, nome:'Kao Gil', curso:'ADS'},
    {ra:112, nome:'Heitor', curso:'BSI'},
    {ra:345, nome:'Ronaldo', curso:'ADS'},
    {ra:678, nome:'Cirilo', curso:'BCC'},
];

function CarregaTabela(dados) {
    // Vinculando o elemento a uma variável
    let tabela = document.querySelector('#tabela');
    
    // Cria a linha do cabeçalho da tabela
    let trCabecalho = document.createElement('tr');

    // Cria as colunas
    let thRA = document.createElement('th');
    let thNome = document.createElement('th');
    let thCurso = document.createElement('th');

    // Colocar o nome de cada coluna
    thRA.textContent = 'RA';
    thNome.textContent = 'Nome';
    thCurso.textContent = 'Curso';

    // Afiliar os headers a linha de cabeçalho
    trCabecalho.appendChild(thRA);
    trCabecalho.appendChild(thNome);
    trCabecalho.appendChild(thCurso);


    // Afiliar a linha do cabeçalho a tabela 
    tabela.appendChild(trCabecalho);

    // Percorrendo o dataset
    for(let i = 0; i < dados.length; i++) {
        
        // Criar linha para cada objeto
        let trLinha = document.createElement('tr');
        let tdRA = document.createElement('td');
        let tdNome = document.createElement('td');
        let tdCurso = document.createElement('td');

        // 
        tdRA.textContent = dados[i].ra;
        tdNome.textContent = dados[i].nome;
        tdCurso.innerHTML = '<strong style="color:green">' + dados[i].curso +'<\strong>';
        trLinha.appendChild(tdRA);
        trLinha.appendChild(tdNome);
        trLinha.appendChild(tdCurso);

        tabela.appendChild(trLinha);
    }
}
