# ☕ Sistema de Pedidos de Cafeteria (C)

Uma aplicação de linha de comando (CLI) desenvolvida em **C** para gerenciar pedidos de uma cafeteria. O sistema calcula o valor total com base na bebida e tamanho, aplica regras de desconto para estudantes e verifica a elegibilidade para brindes promocionais.

## 🎯 Sobre o Projeto
Este projeto foi criado para praticar fundamentos da linguagem C, como manipulação de strings (`string.h`), ponteiros, estruturas de controle (`if/else`), funções modularizadas e formatação de saída no terminal. O sistema simula o fluxo completo de um caixa de cafeteria, desde a captura dos dados do cliente até a emissão do recibo final.

## ⚙️ Funcionalidades
- Captura interativa de dados do cliente via terminal.
- Cálculo dinâmico de preço com base no tipo de bebida e tamanho.
- Aplicação automática de **10% de desconto** para alunos FIAP em pedidos com valor base superior a R$ 15,00.
- Verificação automática de **brinde** para pedidos com valor final igual ou superior a R$ 20,00.
- Código modularizado em funções com responsabilidades únicas.

## 💰 Tabela de Preços Unitários

| Bebida      | Tamanho P | Tamanho M | Tamanho G |
|-------------|-----------|-----------|-----------|
| **Chocolate**| R$ 5,50   | R$ 7,00   | R$ 8,50   |
| **Água**     | R$ 2,00   | R$ 5,00   | R$ 8,00   |
| **Café**     | R$ 4,00   | R$ 5,50   | R$ 7,00   |

## 📜 Regras de Negócio
1. **Desconto Estudantil:** Se o cliente informar que é aluno da FIAP (`Sim`) **E** o valor total sem desconto for **maior que R$ 15,00**, um desconto de 10% é aplicado.
2. **Brinde Promocional:** Se o **valor final** do pedido (após a aplicação do desconto) for **maior ou igual a R$ 20,00**, o cliente recebe um brinde.

## 💻 Como Compilar e Executar

Como este projeto é em C, é necessário ter um compilador instalado (como o **GCC**).
