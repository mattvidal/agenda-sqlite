# agenda-sqlite
Implementação de uma agenda telefônica utilizando a biblioteca SQLite para linguagem C

## Descrição
Deve-se criar um programa que implemente uma Agenda de Contatos com as seguintes características:

a) Cada contato deverá armazenar:
* Nome da pessoa, com até 200 caracteres;
* Números de telefones;
* E-mails.

b) O menu deverá oferecer ao usuário as seguintes opções
* Listar contatos (em ordem alfabética);
* Inserir contato;
* Remover contato;
* Editar contato (inserir/remover telefone, inserir/remover email);
* Limpar toda a agenda.

## Instalação
Execute o comando abaixo no terminal para instalar o SQLite na família Debian/Ubuntu.

```sh
# apt-get install sqlite3 libsqlite3-dev
```
Para visualizar cada arquivo, ou melhor, cada banco de dados, você poderá instalar o aplicativo sqlitebrowser:

```sh
# apt-get install sqlitebrowser
```

Para esse projeto, utilizo o Code Blocks 16.01 no Ubuntu 16.04. E para efetuar a execução correta da IDE, é preciso seguir os seguintes passos:

	Botão direito no nome do projeto > Build options > Linker settings > em "Other linker options", acrescente a linha "-lsqlite3" sem os parênteses.

Esses comandos vão adicionar a lib ao linker corretamente.

