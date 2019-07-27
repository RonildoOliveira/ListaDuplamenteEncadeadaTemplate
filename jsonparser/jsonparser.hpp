#ifndef JSONPARSER_HPP
#define JSONPARSER_HPP

#include <fstream>
#include <regex>
#include <type_traits>

#include <datastructure/dclist.hpp>

template<class Type>
class JsonParser
{
    public:
        DCList<Type> * jsonFileToDSList(std::string jsonFile);
        void DSListToJson();
        JsonParser();
        void put_int(int value);
        void put_float(float value);
        void put_string(std::string value);
    private:
        std::ifstream fileReader;
        DCList<Type> * doubleChainList;
};

template<class Type>
JsonParser<Type>::JsonParser()
{
    this->doubleChainList = new DCList<Type>();
}

template<class Type>
DCList<Type> * JsonParser<Type>::jsonFileToDSList(std::string jsonFile){
    std::string line;

    this->fileReader.open(jsonFile);

    if (this->fileReader.is_open()) {
        while (!this->fileReader.eof()) {

            this->fileReader >> line;
            //std::string subject(line);

            try {
              std::regex regularExpression("(?!\"\\w+\":)(?:(\\d+.\\d+)|\"(\\w+)\")");
              std::sregex_iterator next_token(line.begin(), line.end(), regularExpression);
              std::sregex_iterator end;

              while (next_token != end) {
                std::smatch match = *next_token;
                std::string str = match.str();
                str.erase(std::remove(str.begin(), str.end(), '"'), str.end());

                if(std::is_same<Type, int>::value){
                    const bool is_int = strspn( str.c_str(), "0123456789-" );
                    if(is_int){
                        const int val = std::atoi(str.c_str());
                        put_int(val);
                    }
                }
                else if(std::is_same<Type, float>::value){
                    const bool is_float = strspn( str.c_str(), "-.0123456789" );
                    if(is_float){
                        const double val = std::atof(str.c_str());
                        put_float(val);
                    }
                }
                else if(std::is_same<Type, std::string>::value){
                    const bool is_float = strspn( str.c_str(), "-.0123456789" );
                    if(!is_float){
                        put_string(str);
                    }
                }

                next_token ++;

                }
            }
            catch (std::regex_error& exeption) {
                std::cout << exeption.what() << std::endl;
            }
        }
    }

    return doubleChainList;
}

template<class Type>
void JsonParser<Type>::DSListToJson()
{
    Node<Type> * node = this->doubleChainList->getHeadNode();
    std::string quote = "";
    std::string fileContent =  "";
    std::stringstream ss;

    if(std::is_same<Type, std::string>::value){
        quote = "\"";
    }

    if(this->doubleChainList->isEmpty()){
        std::cerr << "empty"<< std::endl;
    }else{
        ss << "[ ";
        while (node->getNext() != nullptr) {
            ss << "{ " << "\"value\":" << quote << node->getObject()->getValue() << quote << " },";
            node = node->getNext();
        }
        ss << "{ " << "\"value\":" << quote << doubleChainList->getTailNode()->getObject()->getValue() << " }";
        ss << " ]";
    }

    fileContent = ss.str();

    std::ofstream jsonFile;
    jsonFile.open ("output.json");
    jsonFile << fileContent;
    jsonFile.close();

}

template<>
void JsonParser<int>::put_int(int value)
{
    this->doubleChainList->pushFront(value);
}

template<>
void JsonParser<float>::put_float(float value)
{
    this->doubleChainList->pushFront(value);
}

template<>
void JsonParser<std::string>::put_string(std::string value)
{
    this->doubleChainList->pushFront(value);
}

#endif // JSONPARSER_HPP
