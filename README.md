# Super Trunfo - Países / Cidades

## 📌 Descrição do Projeto
Super Trunfo é um jogo de cartas inspirado no clássico jogo de comparação de atributos. Nesta versão em **C**, o jogador cadastra cartas de diferentes cidades, cada uma com atributos como população, área, PIB, pontos turísticos e outros. O jogador então compara duas cartas escolhendo um atributo para determinar o vencedor.  

Esta versão inclui:  
- Cadastro completo de cartas pelo usuário.  
- Cálculo automático de **densidade populacional**, **PIB per capita** e **superpoder**.  
- Comparação interativa com **menu de atributos**.  
- Lógica de vitória com **if-else aninhado**, considerando regras específicas para cada atributo.  
- Mensagens detalhadas de resultado, incluindo empate.

---

## 📝 Funcionalidades
1. Cadastro de cartas por estado e cidade.  
2. Cálculo de densidade populacional e PIB per capita automaticamente.  
3. Comparação de duas cartas com escolha do atributo.  
4. Regras de comparação:  
   - Maior valor vence para todos os atributos **exceto densidade populacional**.  
   - Para densidade populacional, **menor valor vence**.  
5. Exibição clara de resultados, incluindo nomes das cartas, valores e vencedor.

---

## ⚙️ Requisitos
- Compilador C (ex.: GCC, MinGW, Code::Blocks).  
- Sistema operacional Windows, Linux ou macOS.  
- Conhecimentos básicos de terminal para executar programas em C.

---

## 🏃 Como Jogar
1. Clone este repositório ou faça download do arquivo `supertrunfo.c`.
2. Compile o código usando um compilador C, por exemplo:
```bash
gcc supertrunfo.c -o supertrunfo.exe
