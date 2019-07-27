#include <QCoreApplication>
#include <iostream>
#include <fstream>
#include <string>

#include <algorithm>
#include <regex>

#include "template/object.hpp"
#include "datastructure/node.hpp"
#include "datastructure/dclist.hpp"
#include "jsonparser/jsonparser.hpp"

using namespace std;

int main()
{
    /** Template specialization (int) **/
    //DCList<int> * doubleChainList;
    //JsonParser<int> * jParser = new JsonParser<int>();

    /** Template specialization (float) **/
    //DCList<float> * doubleChainList;
    //JsonParser<float> * jParser = new JsonParser<float>();

    /** Template specialization (string) **/
    DCList<string> * doubleChainList;
    JsonParser<string> * jParser = new JsonParser<string>();

    doubleChainList = jParser->jsonFileToDSList("../selecaoFFQuestao01/input/content.json");
    doubleChainList->pushBack("Silva");
    doubleChainList->show();
    jParser->DSListToJson();

    return 0;
}
