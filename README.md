# Minishell

A minimal Unix shell implementation in C, built as part of the 42 curriculum.

## Features

- ✅ Command execution with PATH resolution
- ✅ Built-in commands: `cd`, `pwd`, `echo`, `env`, `export`, `unset`, `exit`
- ✅ Redirections: `<`, `>`, `>>`, `<<` (heredoc)
- ✅ Pipes: `|`
- ✅ Environment variable expansion: `$VAR`, `$?`
- ✅ Quote handling: `'single'`, `"double"`
- ✅ Signal handling: Ctrl+C, Ctrl+D, Ctrl+\

## Building
```bash
make
./minishell
```

## Usage
```bash
minishell> echo "Hello, World!"
Hello, World!
minishell>
```

## Project Structure
```
minishell/
├── src/          # Main shell loop
├── lexer/        # Tokenization
├── parser/       # Command parsing
├── expander/     # Variable expansion
├── executor/     # Command execution
├── built_in/     # Built-in commands
└── libft/        # Library functions
```

## Contributors

- Dimple Gulrajani (https://github.com/dg-does)
- Felix Greiff (https://github.com/feligri)

## License

This project is part of the 42 School curriculum.