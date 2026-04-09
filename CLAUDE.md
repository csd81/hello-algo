# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

**hello-algo** is an open-source educational book on Data Structures and Algorithms featuring animated illustrations and runnable code examples in 14+ programming languages. The site is built with MkDocs Material and supports Simplified Chinese (root), Traditional Chinese (`zh-hant/`), English (`en/`), Japanese (`ja/`), Russian (`ru/`), and Hungarian (`hu/`).

## Local Development

Serve the documentation site locally using Docker:

```bash
docker-compose up -d   # starts at http://localhost:8000
docker-compose down
```

## Running Code Tests

Each language has its own test runner. Run these from the repo root:

**Python** (also requires `black` formatter):
```bash
cd codes/python && python test_all.py
```

**C++** (uses CMake):
```bash
cmake -B codes/cpp/build -DCMAKE_CXX_COMPILER=g++ -DCMAKE_BUILD_TYPE=Release -S codes/cpp
cmake --build codes/cpp/build --config Release
ctest --test-dir codes/cpp/build --build-config Release
```

**C** (same pattern as C++):
```bash
cmake -B codes/c/build -S codes/c
cmake --build codes/c/build
```

**Go**:
```bash
cd codes/go && go build ./...
```

**Java**:
```bash
javac -d codes/java/build $(find codes/java -name "*.java")
```

CI workflows for all 13+ languages live in `.github/workflows/`.

## Repository Structure

```
docs/              # Simplified Chinese content (root language)
en/                # English translation (own mkdocs.yml + docs/ + codes/)
zh-hant/           # Traditional Chinese
ja/                # Japanese
ru/                # Russian
hu/                # Hungarian
codes/             # Canonical algorithm implementations (14+ languages)
overrides/         # MkDocs Material theme customizations
mkdocs.yml         # Main site config (Chinese, v1.3.0, Material theme)
```

Each translation directory mirrors the same chapter structure as `docs/` and includes its own `mkdocs.yml` that inherits from the parent config.

The `codes/` directory at the root is the canonical source. Translation directories (e.g., `en/codes/`) contain language-specific copies that may diverge slightly in comments/naming.

## Content Structure

16 chapters covering: complexity analysis → arrays/linked lists → stacks/queues → hash tables → trees → heaps → graphs → search → sorting → divide & conquer → backtracking → dynamic programming → greedy algorithms.

## Contribution Guidelines

- **Python code** must pass `black` formatter (enforced in CI).
- **C/C++ code** must build cleanly on Windows, macOS, and Ubuntu (gcc/clang/MSVC).
- **Java code** must compile under both Java 11 and Java 17.
- **All code PRs** should include console output in the PR description.
- **Translation PRs** require 2 approvers; English translation workflow is tracked via Notion (linked in `en/CONTRIBUTING.md`).
- PR template is at `.github/pull_request_template.md`.
