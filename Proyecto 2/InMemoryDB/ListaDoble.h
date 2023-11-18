#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <functional>
#include <iomanip>
#include <sstream>
#include <unordered_map>
#include <algorithm>



struct Node {
    std::string data;
    Node* prev;
    Node* next;
    std::string hashValue;
    std::string originalData;
    std::string campo2;
};

class ListaDoble {
private:
    Node* head;
    Node* tail;
    std::string hashFunction(const std::string& searchTerm);
    std::vector<Node*> dataList;
    std::unordered_multimap<std::string, Node*> dataHashMap;


public:
    ListaDoble() : head(nullptr), tail(nullptr) {}
    void addNode(const std::string& data);
    void printList();
    void deleteList();
    std::string funcionhash(const std::string str);
    void searchByKey(const std::string& searchTerm);
   Node* buscarPorLlave(const std::string& llaveBuscada);   
   void mostrarResultados(Node* resultado);
   void searchByValue(const std::string& searchTerm);
   bool busquedaSecuencial(const std::string& data, const std::string& searchTerm);
};
