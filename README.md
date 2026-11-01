MP3 Tag Reader and Editor

A command-line application developed using C to read and edit metadata tags in MP3 files.

Overview

The MP3 Tag Reader and Editor allows users to view and modify selected metadata information stored in MP3 files.
The application works with ID3 tags and provides command-line options to display MP3 metadata or update specific tag values.

Features

View MP3 Tags
- Display the metadata information stored in an MP3 file.
- Read details such as title, artist, album, year, composer, and other supported tags.
- Display the extracted information in a structured format.

Edit MP3 Tags
Modify selected metadata fields:

- Song Title
- Artist Name
- Album Name
- Year
- Genre / Content Type
- Composer

Help Option
- Display command usage and available options.

Technologies Used

- Programming Language: C
- Compiler: GCC
- File Handling: Standard C file I/O
- MP3 Metadata: ID3 Tags
- Development Environment: VS Code

Concepts Applied

- Command-line argument handling (`argc` and `argv`)
- File handling in binary mode
- Structures of modular C source files and header files
- String handling and comparison
- Pointers and functions
- Binary file reading and writing
- Working with ID3 metadata frames

Project Structure

```text
MP3-Tag-Reader-Editor/
│
├── main.c
├── mp3.h
├── mp3_definitions.c
├── README.md
└── .gitignore
```

Compilation

Make sure GCC is installed.

Compile the project:

```bash
gcc main.c mp3_definitions.c -o mp3_tag_editor
```

Usage

1. Display Help

```bash
./mp3_tag_editor --help
```

2. View MP3 Metadata

```bash
./mp3_tag_editor -v sample.mp3
```

3. Edit MP3 Metadata

Edit Song Title
```bash
./mp3_tag_editor -e -t "New Song Title" sample.mp3
```

Edit Artist Name
```bash
./mp3_tag_editor -e -a "New Artist" sample.mp3
```

Edit Album Name
```bash
./mp3_tag_editor -e -A "New Album" sample.mp3
```

Edit Year
```bash
./mp3_tag_editor -e -y "2026" sample.mp3
```

Edit Genre / Content Type
```bash
./mp3_tag_editor -e -m "Rock" sample.mp3
```

Edit Composer
```bash
./mp3_tag_editor -e -c "Composer Name" sample.mp3
```

Learning Outcomes

Through this project, I gained practical experience in:

- Handling command-line arguments in C.
- Reading and writing binary files.
- Understanding MP3 metadata and ID3 tags.
- Working with file pointers and file positioning.
- Implementing modular programming using multiple source files.
- Modifying specific metadata fields in an existing file.

Future Improvements

- Support additional ID3 metadata fields.
- Improve input and file validation.
- Strengthen error handling for unsupported or invalid MP3 files.
- Improve compatibility with different ID3 versions.

Author

**Karthikeyan Eswaran**

Embedded Systems Trainee | Emertxe Information Technologies
