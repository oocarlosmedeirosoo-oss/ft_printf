This project has been created as part
of the 42 curriculum by cbarbosa
# ft_printf

Reimplementação do comportamento idêntico da função `printf()` da libc em C, desenvolvida como projeto da **42 Lisboa**.

---

## Sobre o Projeto

O `ft_printf` é uma versão própria do `printf()` original. O principal desafio é trabalhar com **funções variádicas** — funções que aceitam um número variável de argumentos — usando a biblioteca `<stdarg.h>`.

O resultado final é uma biblioteca estática `libftprintf.a` que pode ser integrada em projetos futuros da 42.

Para a criação deste projeto, o peer-to-peer foi a maior fonte de informação. Conceitos como va_list, va_start, va_arg e va_end foram obtidos através de videos no YouTube e AI para a explicação de conceitos para um melhor entedimento.

---

## Conversores Suportados

| Conversor | Descrição |
|-----------|-----------|
| `%c` | Imprime um único caractere |
| `%s` | Imprime uma string |
| `%p` | Imprime um ponteiro em formato hexadecimal |
| `%d` | Imprime um número decimal (base 10) |
| `%i` | Imprime um inteiro em base 10 |
| `%u` | Imprime um número decimal sem sinal |
| `%x` | Imprime um número em hexadecimal minúsculo |
| `%X` | Imprime um número em hexadecimal maiúsculo |
| `%%` | Imprime o símbolo `%` |

---

## Estrutura do Projeto

```
ft_printf/
├── Makefile
├── ft_printf.h          ← protótipos e includes
├── ft_printf.c          ← função principal + dispatcher
├── ft_printf_chars.c    ← %c e %s
├── ft_printf_nbrs.c     ← %d, %i e %u
└── ft_printf_hex.c      ← %x, %X e %p
```

---

## Compilação

```bash
make        # compila e gera libftprintf.a
make clean  # remove os ficheiros objeto (.o)
make fclean # remove tudo incluindo a biblioteca
make re     # fclean + all
```

---

## Utilização

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Olá, %s!\n", "mundo");
    ft_printf("Número: %d\n", 42);
    ft_printf("Hex: %x\n", 255);
    ft_printf("Ponteiro: %p\n", &main);
    return (0);
}
```

Compila o teu programa linkando a biblioteca:

```bash
cc main.c -L. -lftprintf -o programa
./programa
```

---

## 🔍 Casos Especiais

| Caso | Comportamento |
|------|--------------|
| `%s` com `NULL` | Imprime `(null)` |
| `%p` com `NULL` | Imprime `(nil)` |
| `%d` com `INT_MIN` | Imprime `-2147483648` corretamente |

---

## Conceitos Aprendidos

- Funções variádicas com `va_list`, `va_start`, `va_arg`, `va_end`
- Recursão para conversão de bases numéricas
- Criação de biblioteca estática com `ar rcs`
- Organização de código seguindo **La Norme** da 42

---

## Normas

Este projeto foi desenvolvido de acordo com **La Norme** da 42:
- Máximo 25 linhas por função
- Máximo 5 variáveis por função
- Sem `for`, sem `do...while`, sem operador ternário
- Tabs para indentação

