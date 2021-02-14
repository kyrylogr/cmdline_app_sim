
#include <iostream>
#include <string>

void print_usage_info(std::ostream & os)
{
    const char* usage = R"(Command line simulation app.
Can generate output to standard output, standard error and return error codes.

Usage: cmdline_app_sim [-stdout text] [-stderr text] [-retcode code]
  -stdout text        : outputs text to standard output
  -stderr text        : outputs text to standard error output
  -return_code code   : returns spicifed code as application return code)";
    os << usage << "\n";
}

std::string pstdout("-stdout");
std::string pstderr("-stderr");
std::string pretcode("-return_code");

int main(int argc, const char* argv[])
{
    int code = 0;
    if (argc <= 1)
        print_usage_info(std::cout);
    for (int i = 1; i < argc-1; ++i) {
        auto * param = argv[i];
        auto * value = argv[i+1];
        if (param == pstdout)
            std::cout << value;
        else if (param == pstderr)
            std::cerr << value;
        else if (param == pretcode)
            code = std::stoi(value);
    }
    return code;
}