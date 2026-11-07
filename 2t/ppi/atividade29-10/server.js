// Servidor de cadastro de pães - usa somente os core modules http, url e fs
const http = require('http');
const url = require('url');
const fs = require('fs');

const PORTA = 3010;
const ARQUIVO = 'paes.txt';
const pgform = 'index.html'

// ---------- Páginas HTML ----------
function paginaFormulario(mensagem) {
  return `<!DOCTYPE html>
<html lang="pt-BR">
<head>
  <meta charset="UTF-8">
  <title>Padaria - Cadastro de Pães</title>
</head>
<body>
  <h1>Cadastro de Pães</h1>
  ${mensagem ? `<p><strong>${mensagem}</strong></p>` : ''}
  <form action="/cadastrar" method="POST">
    <p>
      <label>Nome:<br>
        <input type="text" name="nome" required>
      </label>
    </p>
    <p>
      <label>Tipo de fermentação:<br>
        <select name="fermentacao" required>
          <option value="natural">Natural</option>
          <option value="biológica">Biológica</option>
          <option value="química">Química</option>
        </select>
      </label>
    </p>
    <p>
      <label>Ingredientes:<br>
        <input type="text" name="ingredientes" required>
      </label>
    </p>
    <p>
      <label>Preço por kg (R$):<br>
        <input type="number" name="preco" step="0.01" min="0" required>
      </label>
    </p>
    <button type="submit">Cadastrar</button>
  </form>
  <p><a href="/listar">Ver pães cadastrados</a></p>
</body>
</html>`;
}

function paginaLista(conteudo) {
  return `<!DOCTYPE html>
<html lang="pt-BR">
<head>
  <meta charset="UTF-8">
  <title>Pães cadastrados</title>
</head>
<body>
  <h1>Pães cadastrados</h1>
  <pre>${conteudo}</pre>
  <p><a href="/">Voltar ao cadastro</a></p>
</body>
</html>`;
}

// ---------- Funções auxiliares ----------
function responder(res, status, html) {
  res.writeHead(status, { 'Content-Type': 'text/html; charset=utf-8' });
  res.end(html);
}

// Remove quebras de linha para o usuário não "quebrar" o formato do .txt
function limpar(texto) {
  return String(texto || '').replace(/[\r\n]+/g, ' ').trim();
}

// Evita que o texto digitado seja interpretado como HTML na listagem
function escaparHtml(texto) {
  return texto
    .replace(/&/g, '&amp;')
    .replace(/</g, '&lt;')
    .replace(/>/g, '&gt;');
}

// ---------- Servidor ----------
const servidor = http.createServer((req, res) => {
  const rota = url.parse(req.url, true).pathname;

  // GET / -> exibe o formulário
  if (req.method === 'GET' && rota === '/') {
    return responder(res, 200, paginaFormulario());
  }

  // POST /cadastrar -> recebe os dados e grava no paes.txt
  if (req.method === 'POST' && rota === '/cadastrar') {
    let corpo = '';

    req.on('data', (pedaco) => {
      corpo += pedaco;
    });

    req.on('end', () => {
      const dados = new URLSearchParams(corpo);

      const nome = limpar(dados.get('nome'));
      const fermentacao = limpar(dados.get('fermentacao'));
      const ingredientes = limpar(dados.get('ingredientes'));
      const preco = Number(dados.get('preco'));

      if (!nome || !fermentacao || !ingredientes || isNaN(preco)) {
        return responder(res, 400, paginaFormulario('Preencha todos os campos corretamente.'));
      }

      const precoFormatado = 'R$' + preco.toFixed(2).replace('.', ',');

      const registro =
        `Nome: ${nome}\n` +
        `Tipo de fermentação: ${fermentacao}\n` +
        `Ingredientes: ${ingredientes}\n` +
        `Preço: ${precoFormatado}\n`;

      // appendFile cria o arquivo se não existir e acrescenta ao final
      fs.appendFile(ARQUIVO, registro, 'utf8', (erro) => {
        if (erro) {
          console.error(erro);
          return responder(res, 500, paginaFormulario('Erro ao salvar o pão.'));
        }
        responder(res, 200, paginaFormulario('Pão cadastrado com sucesso!'));
      });
    });

    return;
  }

  // GET /listar -> mostra o conteúdo do paes.txt
  if (req.method === 'GET' && rota === '/listar') {
    return fs.readFile(ARQUIVO, 'utf8', (erro, conteudo) => {
      if (erro) {
        // ENOENT = arquivo ainda não existe (nenhum pão cadastrado)
        return responder(res, 200, paginaLista('Nenhum pão cadastrado ainda.'));
      }
      responder(res, 200, paginaLista(escaparHtml(conteudo)));
    });
  }

  // Qualquer outra rota
  responder(res, 404, '<h1>404 - Página não encontrada</h1><a href="/">Voltar</a>');
});

servidor.listen(PORTA, () => {
  console.log(`Servidor rodando em http://localhost:${PORTA}`);
});
