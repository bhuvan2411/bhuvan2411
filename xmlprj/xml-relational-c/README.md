# XML Relational C Project

This project is designed to efficiently parse XML data and dynamically create and manage relational tables based on the parsed information. It maintains referential integrity among the tables to ensure that relationships between data are preserved.

## Project Structure

```
xml-relational-c
├── src
│   ├── main.c                # Entry point of the application
│   ├── xml_parser.c          # XML parsing logic implementation
│   ├── xml_parser.h          # Header file for XML parser
│   ├── table_manager.c       # Logic for managing relational tables
│   ├── table_manager.h       # Header file for table manager
│   ├── referential_integrity.c# Logic for maintaining referential integrity
│   ├── referential_integrity.h# Header file for referential integrity
│   └── utils
│       ├── memory.c          # Utility functions for memory management
│       ├── memory.h          # Header file for memory utilities
│       ├── string_utils.c     # Utility functions for string manipulation
│       └── string_utils.h     # Header file for string utilities
├── include
│   ├── xml_parser.h          # Public interface for XML parser
│   ├── table_manager.h       # Public interface for table manager
│   ├── referential_integrity.h# Public interface for referential integrity
│   ├── memory.h              # Public interface for memory utilities
│   └── string_utils.h        # Public interface for string utilities
├── tests
│   ├── test_xml_parser.c     # Unit tests for XML parser
│   ├── test_table_manager.c   # Unit tests for table manager
│   └── test_referential_integrity.c # Unit tests for referential integrity
├── data
│   └── sample.xml            # Sample XML document for testing
├── Makefile                  # Build instructions for the project
└── README.md                 # Project documentation
```

## Setup Instructions

1. **Clone the repository**:
   ```
   git clone <repository-url>
   cd xml-relational-c
   ```

2. **Build the project**:
   Use the provided Makefile to compile the project:
   ```
   make
   ```

3. **Run the application**:
   After building, you can run the application using:
   ```
   ./xml-relational-c
   ```

## Usage

- The application will read the XML data from `data/sample.xml`.
- It will parse the XML and create relational tables dynamically based on the structure of the XML.
- The tables will maintain referential integrity, ensuring that all relationships are valid.

## Contributing

Contributions are welcome! Please submit a pull request or open an issue for any enhancements or bug fixes.

## License

This project is licensed under the MIT License. See the LICENSE file for more details.