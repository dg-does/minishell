_This project has been created as part of the 42 curriculum by <fgreiff> and <digulraj>._

# Minishell - Description

A minimal Unix shell implementation in C which imitates bash as closely as possible. 

## Features

- ✅ Command execution with PATH resolution
- ✅ Built-in commands: `cd`, `pwd`, `echo`, `env`, `export`, `unset`, `exit`
- ✅ Redirections: `<`, `>`, `>>`, `<<` (heredoc)
- ✅ Pipes: `|`
- ✅ Environment variable expansion: `$VAR`, `$?`
- ✅ Quote handling: `'single'`, `"double"`
- ✅ Signal handling: Ctrl+C, Ctrl+D, Ctrl+\

## Instructions
```bash
make
./minishell
```
minishell> echo "Hello, World!"
Hello, World!
minishell>

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

## Resources 

- https://www.geeksforgeeks.org/c/making-linux-shell-c/ - foundational walkthrough on concepts of a Linux Shell
- https://harm.co/42/minishell — 42-specific guide covering parsing, builtins, and edge cases
- Bash manual ("man bash" in a terminal) — the ground truth for expected behavior

### AI usage description:

Claude (claude.ai) was used to breakdown the subject into smaller concepts to ease learning at the start of the project, and additionally as a debugging and code review assistant throughout the project. 
All code was written and understood by the student — AI was used interactively to explain why bugs occurred, share resources on related topics, and to verify fixes - similar to how one might use a more experienced peer for code review.

## License

This project is part of the 42 School curriculum.