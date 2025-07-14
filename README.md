# Imobiliária - Agendamento de Avaliações
O objetivo deste projeto é implementar um gerador de agendas que distribua as avaliações de imóveis entre corretores-avaliadores, calculando o horário de início de cada visita conforme um algoritmo específico. O programa processa dados de entrada sobre corretores, clientes e imóveis, e produz uma agenda automática de avaliações otimizada.

## Colaboradores do Projeto:
- [*Alan0Franklin*](https://github.com/Alan0Franklin)
- [*jhonatanthiago*](https://github.com/jhonatanthiago)
- [*soggart*](https://github.com/soggart)


## Sumário

- [1. Estrutura](#1-estrutura)
- [2. Descrição das Classes](#2-descricao_das_classes)
- [3. Descrição da Estrutura e das Funções](#3-descricao_da_estrutura_e_funcoes)
- [4. Como Compilar e Executar](#4-como_compilar_e_executar)

---

## 1. Estrutura <a name="1-estrutura"></a>
```
Imobiliaria_Agendamento_de_Avaliacoes/
├── Entradas_+_Saidas_Esperadas
│   ├── teste1_entrada.txt
│   ├── teste1_saida.txt
│   ├── teste2_entrada.txt
│   ├── teste2_saida.txt
│   ├── teste3_entrada.txt
│   └── teste3_saida.txt
├── Makefile
├── README.md
├── cliente.cpp
├── cliente.hpp
├── corretor.cpp
├── corretor.hpp
├── imovel.cpp
├── imovel.hpp
├── main.cpp
├── pessoa.cpp
├── pessoa.hpp
├── util.cpp
└── util.hpp
```

---


## 2. Descrição das Classes <a name="2-descricao_das_classes"></a>

### ➕ class Pessoa
Classe abstrata para compartilhar atributos em comum de entidades representadas por indivíduos.
- `id`: Número inteiro que representa o ID da pessoa (dependendo da função da pessoa que vai herdar essa classe na imobiliária).
- `nome`: String correspondente ao nome da pessoa.
- `telefone`: String correspondente ao telefone da pessoa.

#### + virtual ~Pessoa()
Destrutor virtual para que o destrutor da classe derivada seja chamado corretamente e não ocorra vazamento de memória ou recursos.

#### + void setNome(std::string nome)
Método para atribuir um `nome` para o nome da pessoa.
- `nome`: String o qual deseja-se definir como nome da pessoa.

#### + void setTelefone(std::string telefone)
Método para atribuir um `telefone` para o telefone da pessoa.
- `telefone`: String o qual deseja-se definir como telefone da pessoa.

#### + std::string getNome()
Método para acessar o `nome` da pessoa. Retornando o nome em formato de string.

#### + std::string getTelefone()
Método para acessar o `telefone` da pessoa. Retornando o telefone em formato de string.

#### + int getId() const
Método para acessar o `id` da pessoa. Retornando o ID em formato de inteiro.

#### + virtual void exibirInformacoes()
Método virtual puro para exibir as informações da pessoa, obrigando as classes derivadas a fornecer uma implementação para esse método conforme as informações que cada uma possuir.

---

### ➕ class Corretor : public Pessoa
Classe derivada de `Pessoa` que representa um corretor da imobiliária.
- `nextId`: Número inteiro que se mantém estático para todos os objetos da classe `Corretor`, é o que permite o programa gerar `id`s sequenciais para cada `Corretor`, começando em 1.
- `avaliador`: Booleana que indica se aquele é um corretor-avaliador. Com `true` indicando que sim, que aquele corretor é um avaliador, e `false` indicando que não, que aquele corretor não é um avaliador.
- `lat`: Número flutante que representa a latitude onde o corretor mora.
- `lng`: Número flutante que representa a longitude onde o corretor mora.

#### + Corretor()
Construtor padrão para criar um objeto `Corretor` que fica encarregado apenas de autoincrementar o `id` com ajuda do `nextId`, deixando o papel de atribuir valores aos outros atributos da classe para os "setters".

#### + Corretor(std::string nome, std::string telefone, int avaliador, double lat, double lng)
Construtor para criar um objeto `Corretor` que autoincrementa o `id` com ajuda do `nextId`, além de atribuir o `nome`, `telefone`, `avaliador`, `lat` e `lng` aos atributos do objeto `Corretor`.
- `nome`: String o qual deseja-se definir como nome do corretor.
- `telefone`: String o qual deseja-se definir como telefone do corretor.
- `avaliador`: Inteiro o qual define se o corretor como avaliador ou não. Com `1` indicando que sim, que aquele corretor é um avaliador, e `0` indicando que não.
- `lat`: Número flutante o qual deseja-se definir como a latitude onde o corretor mora.
- `lng`: Número flutante o qual deseja-se definir como a longitude onde o corretor mora.

#### + void setAvaliador(int avaliador)
Método para atribuir se tal corretor é um avaliador ou não.
- `avaliador`: Inteiro o qual define se o corretor como avaliador ou não. Com `1` indicando que sim, que aquele corretor é um avaliador, e `0` indicando que não.

#### + void setLatitude(double lat)
Método para atribuir a latitude (`lat`) onde o corretor mora.
- `lat`: Número flutante o qual deseja-se definir como a latitude onde o corretor mora.

#### + void setLongitude(double lng)
Método para atribuir a longitude (`lng`) onde o corretor mora.
- `lng`: Número flutante o qual deseja-se definir como a longitude onde o corretor mora.

#### + bool getAvaliador()
Método para acessar o atributo `avaliador` do corretor. Retornando uma booleana que indica se aquele é um corretor-avaliador.

#### + double getLatitude()
Método para acessar a `lat` da pessoa. Retornando a latitude em formato de número flutuante.

#### + double getLongitude()
Método para acessar a `lng` da pessoa. Retornando a longitude em formato de número flutuante.

#### + void exibirInformacoes()
Método para exibir as informações do corretor, no caso seu `id`, `nome`, `telefone`, `lat`, `lng` e `avaliador`.

---

### ➕ class Cliente : public Pessoa
Classe derivada de `Pessoa` que representa um cliente da imobiliária.
- `nextId`: Número inteiro que se mantém estático para todos os objetos da classe `Cliente`, é o que permite o programa gerar `id`s sequenciais para cada `Cliente`, começando em 1.

#### + Cliente()
Construtor padrão para criar um objeto `Cliente` que fica encarregado apenas de autoincrementar o `id` com ajuda do `nextId`, deixando o papel de atribuir valores aos outros atributos da classe para os "setters".

#### + Cliente(std::string nome, std::string telefone)
Construtor para criar um objeto `Cliente` que autoincrementa o `id` com ajuda do `nextId`, além de atribuir o `nome` e `telefone` aos atributos do objeto `Cliente`.
- `nome`: String o qual deseja-se definir como nome do cliente.
- `telefone`: String o qual deseja-se definir como telefone do cliente.

#### + void exibirInformacoes()
Método para exibir as informações do cliente, no caso seu `id`, `nome`, `telefone`.

---

### ➕ class Imovel
Classe que representa um imóvel da imobiliária.
- `nextId`: Número inteiro que se mantém estático para todos os objetos da classe `Imovel`, é o que permite o programa gerar `id`s sequenciais para cada `Imovel`, começando em 1.
- `id`: Número inteiro que representa o ID do imóvel (na imobiliária).
- `tipo`: String correspondente ao tipo de imóvel (entre Casa, Apartamento e Terreno).
- `proprietarioId`: Número inteiro que representa o ID do proprietário do imóvel (na imobiliária).
- `endereco`: String correspondente ao endereço do imóvel.
- `lat`: Número flutante que representa a latitude da localização do imóvel.
- `lng`: Número flutante que representa a longitude da localização do imóvel.
- `preco`: Número flutante que representa o preço do imóvel.
  
#### + Imovel()
Construtor padrão para criar um objeto `Imovel` que fica encarregado apenas de autoincrementar o `id` com ajuda do `nextId`, deixando o papel de atribuir valores aos outros atributos da classe para os "setters".

#### + Imovel(std::string tipo, int proprietarioId, std::string endereco, double lat, double lng, double preco)
Construtor para criar um objeto `Imovel` que autoincrementa o `id` com ajuda do `nextId`, além de atribuir o `tipo`, `proprietarioId`, `endereco`, `lat`, `lng` e `preco` aos atributos do objeto `Imovel`.
- `tipo`: String o qual deseja-se definir como tipo de imóvel (entre Casa, Apartamento e Terreno).
- `proprietarioId`: Número inteiro o qual deseja-se definir como o ID do proprietário do imóvel (na imobiliária).
- `endereco`: String o qual deseja-se definir como o endereço do imóvel.
- `lat`: Número flutante o qual deseja-se definir como a latitude da localização do imóvel.
- `lng`: Número flutante o qual deseja-se definir como a longitude da localização do imóvel.
- `preco`: Número flutante o qual deseja-se definir como o preço do imóvel.

#### + int getId()
Método para acessar o `id` do imóvel. Retornando o ID em formato de inteiro.

#### + void setTipo(std::string tipo)
Método para atribuir um `tipo` para o tipo do imóvel.
- `tipo`: String o qual deseja-se definir como tipo de imóvel (entre Casa, Apartamento e Terreno).

#### + void setIdDoProprietario(int proprietarioId)
Método para atribuir um `proprietarioId` para o ID do proprietário do imóvel.
- `proprietarioId`: Número inteiro o qual deseja-se definir como o ID do proprietário do imóvel (na imobiliária).

#### + void setEndereco(std::string endereco)
Método para atribuir um `endereco` para o endereço do imóvel.
- `endereco`: String o qual deseja-se definir como o endereço do imóvel.

#### + void setLatitude(double lat)
Método para atribuir a latitude (`lat`) da localização do imóvel.
- `lat`: Número flutante o qual deseja-se definir como a latitude da localização do imóvel.

#### + void setLongitude(double lng)
Método para atribuir a longitude (`lng`) da localização do imóvel.
- `lng`: Número flutante o qual deseja-se definir como a longitude da localização do imóvel.

#### + void setPreco(double preco)
Método para atribuir um `preco` para o preço do imóvel.
- `preco`: Número flutante o qual deseja-se definir como o preço do imóvel.

#### + std::string getTipo()
Método para acessar o `tipo` do imóvel. Retornando o tipo em formato de string.

#### + int getIdDoProprietario()
Método para acessar `proprietarioId`, o ID do proprietário do imóvel. Retornando esse ID em formato de inteiro.

#### + std::string getEndereco()
Método para acessar o `endereco` do imóvel. Retornando o endereço em formato de string.

#### + double getLatitude()
Método para acessar a `lat` do imóvel. Retornando a latitude em formato de número flutuante.

#### + double getLongitude()
Método para acessar a `lng` do imóvel. Retornando a longitude em formato de número flutuante.

#### + double getPreco()
Método para acessar o `preco` do imóvel. Retornando o preço em formato de número flutuante.

#### + void exibirInformacoes()
Método para exibir as informações do corretor, no caso seu `id`, `tipo`, `proprietarioId`, `lat`, `lng`, `preco` e `endereco`

---

## 3. Descrição da Estrutura e das Funções <a name="3-descricao_da_estrutura_e_funcoes"></a>

### + struct PessoaIDComparator 
Estrutura que define um critério de ordenação entre dois corretores com base em seus respectivos `id`s. Essa lógica permite utilizar mapas (`std::map`) em que os corretores são organizados em ordem crescente de `id`, facilitando buscas e inserções ordenadas.

#### + bool operator()(const Corretor* a, const Corretor* b) const
Método que verifica se o `id` do corretor `a` é menor que o `id` do corretor `b`. Retorna 1 caso a condição seja verdadeira, e 0 caso contrário.
- `a`: Ponteiro para um tal `Corretor` a.
- `b`: Ponteiro para um tal `Corretor` b.

### + double haversine(double lat1, double lng1, double lat2, double lng2)
Função haversine, usada para calcular a distância entre das coordenadas na superfície do globo. Recebendo como parâmetros as latitudes (`lat`) e as longitudes (`lng`) de cada um desses pontos e retornando a distância (em km).
- `lat1`: Número flutante que representa a latitude de um ponto 1.
- `lng1`: Número flutante que representa a longitude de um ponto 1.
- `lat2`: Número flutante que representa a latitude de um ponto 2.
- `lng1`: Número flutante que representa a longitude de um ponto 2.

### + void imprimirAgenda(std::map<Corretor*, std::vector<Imovel*>, PessoaIDComparator>& Agenda)
Função responsável por gerar a agenda de visitas dos avaliadores, a partir de um mapa chamado `Agenda`, no qual as chaves são ponteiros para corretores-avaliadores e os valores são vetores contendo os imóveis que cada avaliador deve visitar. Para cada avaliador, a simulação começa às **09:00**, considerando sua localização inicial. A cada passo, é selecionado o imóvel **ainda não visitado** mais próximo da posição atual (seja a localização inicial ou o último imóvel visitado). O tempo de deslocamento até o imóvel é calculado com base na fórmula `distância × 2 minutos` e adicionado ao horário atual. Em seguida, a visita é agendada para esse horário, e **60 minutos** são somados ao relógio para representar a duração da avaliação. Esse processo se repete até que todos os imóveis atribuídos ao avaliador tenham sido visitados e agendados.
- `Agenda`: Um mapa que contém chaves como ponteiros para corretores-avaliadores e que armazena valores como vetores de imóveis que p tal dado corretor-avaliador (apontada pelo ponteiro da chave) deve avaliar.

---

## 4. Como Compilar e Executar <a name="4-como_compilar_e_executar"></a>
Para compilar os arquivos, use o comando `make` em um terminal no diretório/pasta que o `Makefile` estiver. Este comando automatizará a compilação e gerará um executável chamado `imobiliaria`.

Esse programa recebe lê o conteúdo do `cout` redirecionado de um arquivo `entrada.txt` com o `<`, como se fosse digitado pelo terminal, e será imprimido `cin` redirecionado para um arquivo `saida.txt` com o `>`, como se fosse impresso no terminal. Para isso use o seguinte comando a depender do seu terminal:

*   **Windows (Command Prompt):** `imobiliaria.exe < entrada.txt > saida.txt`
*   **Linux/macOS (Terminal):** `./imobiliaria < entrada.txt > saida.txt`



### Formato de Entrada Padrão
O programa lê **exatamente** neste formato:
```
[número de corretores]
[telefone] [avaliador] [latitude] [longitude] [nome]
...
[número de clientes]
[telefone] [nome]
...
[número de imóveis]
[tipo] [proprietarioId] [latitude] [longitude] [preco] [endereco]
...
```

Exemplo concreto (para 2 corretores e 3 imóveis):
```
2
123456789 1 -3.74 -38.52 João
987654321 1 -3.75 -38.55 Maria

2
111222333 Carlos
444555666 Ana

3
Casa 1 -3.75 -38.50 300000.0 RuaA123
Apartamento 2 -3.77 -38.47 200000.0 RuaB456
Terreno 1 -3.76 -38.53 150000.0 RuaC789 
```

**Observações:**
- **Texto livre sempre no fim da linha.** Assim é possível ler todos os valores numéricos com `>>` e depois usar `std::getline` para pegar o restante da linha.
- `avaliador`: `1` para sim, `0` para não.
- `nome` e `endereco` podem conter espaços.

### Formato da Saída Padrão
O programa, conforme o `main.cpp` foi elaborado, imprime **apenas** o agendamento, sem nenhum texto adicional.
```
Corretor [ID]
[HH:MM] Imóvel [ID]
[HH:MM] Imóvel [ID]

Corretor [ID]
[HH:MM] Imóvel [ID]
...
```

Exemplo concreto (para 2 corretores e 3 imóveis):
```
Corretor 1
09:04 Imóvel 1
10:11 Imóvel 3

Corretor 2
09:18 Imóvel 2
```

**Observações:**
- O formato de hora é `HH:MM` (Horas e minutos com zero à esquerda, se necessário).
- Cada agendamento para corretores diferentes é separado com uma linha em branco.

---
