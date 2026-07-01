#include <iostream>
#include <fstream>
#include <string>
// take in the bf code as string, and translate to cpp string for transpilation
void bfTranspile(const std::string& bfCode, std::ostream& output){
    // preprocessor directives
    output << "#include <iostream>\n";
    output << "#include <vector>\n";
    // upon translation, use vector of 30000 1 byte memory blocks
    // since c++ doesn't worry about white space, I split by single
    // line escape for output code
    output << "int main() {\n";
    output << "std::vector<unsigned char> tape(30000, 0);\n";
    output << "auto ptr = tape.begin();\n";
    // for each character from the bf code string, 
    // look for each case from the 8 operators, putting 
    // the c++ equivalent into the output buffer.
    for (char c : bfCode) {
        switch (c) {
            case '>': output << "++ptr;\n"; break;
            case '<': output << "--ptr;\n"; break;
            case '+': output << "++*ptr;\n"; break;
            case '-': output << "--*ptr;\n"; break;
            case '.': output << "std::cout << *ptr;\n"; break;
            case ',': output << "std::cin >> *ptr;\n"; break;
            case '[': output << "while (*ptr) {\n"; break;
            case ']': output << "}\n"; break;
            default: break; // Ignore non-Brainfuck characters
        }
    }
    // close main
    output << "return 0;\n";
    output << "}\n";
}

int main(int argc, char* argv[]) {
    // input logic
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <input.bf> <output.cpp>\n";
        return 1;
    }
    std::ifstream in(argv[1]);
    if (!in) {
        std::cerr << "Error: Cannot open input file.\n";
        return 1;
    }
    std::string code((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());
    std::ofstream out(argv[2]);
    bfTranspile(code, out);
    std::cout << "Compilation successful! Generated C++ code written to " << argv[2] << "\n";
    return 0;
}
