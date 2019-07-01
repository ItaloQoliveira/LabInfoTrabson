# LabInfoTrabson
Lab info homerworkerson -> Algum dia, quando eu souber mais, farei novamente isso daqui, ver as mudanças que virão com o conhecimento :V
## 01>
 Fazer um programa em Linguagem C para simular um sistema bancário contendo:

a) contas corrente (número da conta; nome do cliente; saldo; limite);
b) contas poupança (número da conta; nome do cliente; saldo). 
- No banco pode existir até 50 contas de cada tipo.
- Quando uma conta é aberta o saldo é zero.
- Limite de crédito é fixo em R$ 500,00.
- Criar um menu de opções para o bom funcionamento do sistema (pode criar submenus).
- Validar campos quando necessário.
- Número da conta é auto incremental ("eterno").

Funções obrigatórias:
1) uma função para criar conta, e receber os dados do cliente;
2) uma função para consultar conta, por nome e/ou número da conta;
3) uma função para excluir conta;
4) uma função para listar todas as contas (ordem de número da conta);
5) uma função para listar todas as contas (ordem alfabética do nome do cliente);

6) uma função sacar(...) que deverá subtrair do saldo do cliente o valor passado como argumento, se possível;
7) uma função depositar(...) que acresce no saldo o valor passado como argumento;

## 02>
Fazer um programa em Linguagem C para simular uma agenda de telefones.

Cada pessoa da agenda deve ter os seguintes dados:
• Nome
• E-mail
• Endereço (contendo campos para rua, número, bairro, cep, cidade, estado).
• Telefone (contendo campos para DDD e número)
• Data de aniversário (contendo campos para dia, mês, ano).
• Observações (uma string para alguma observação especial).

Fazer:
(a) Definir as estruturas acima.
(b) Declarar a variável agenda (vetor) com capacidade de agendar até 100 pessoas.
(c) Criar uma função de busca por primeiro nome: imprime os dados da pessoa com esse nome (se tiver mais de uma pessoa, imprime para todas).
(d) Criar uma função de busca por mês de aniversário: imprime os dados de todas as pessoas que fazem aniversário nesse mês.
(e) Criar uma função de busca por número de telefone: imprime os dado da pessoa com esse respectivo número.
(f) Criar uma função para listar pessoas - por ordem alfabética de nome.
(g) Criar uma função para excluir pessoas - retira todos os dados dessa pessoa e readeque o vetor de pessoas, se necessário.
(h) Criar uma função para imprimir a agenda com as opções:
      • Imprime somente nome, telefone e e-mail (ordem alfabética de nome).
      • Imprime somente nome, telefone e e-mail (separado por localidade).
      • Imprime todos os dados (ordem alfabética de nome).
(i) O programa deve ter um menu principal oferecendo as opções acima.


Validações: criar funções de validação e não permitir cadastrar na agenda pessoas com valores inválidos.

Validar data: dias entre 1 e 30 (inclusive); mês entre 1 e 12 (inclusive); anos entre 1900 e data corrente;
Validar telefone: 2 dígitos numéricos entre parênteses (significa o DDD); 4 ou 5 dígitos numéricos; um tracinho; 4 dígitos numéricos.
Validar email: sequencia > 2 dígitos; um @; sequencia > 2 dígitos; um ponto; sufixo COM (tudo em minúsculo)
Validar CEP: 5 dígitos numéricos; um tracinho; 3 dígitos numéricos.
Validar estado: somente uma das 27 siglas dos estados brasileiros (tudo em maiúsculo).