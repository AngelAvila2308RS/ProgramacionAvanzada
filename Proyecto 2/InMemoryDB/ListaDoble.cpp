#include "ListaDoble.h"
#include <iostream>
#include <fstream>
#include <string>
#include <functional>
#include <iomanip>
#include <sstream>
#include <unordered_map>
#include <algorithm>


void ListaDoble::addNode(const std::string& data) {
    std::string firstData = data.substr(0, data.find(','));
    std::string hashedFirstData = funcionhash(firstData);

    Node* newNode = new Node{ data, nullptr, nullptr, hashedFirstData, firstData };

    if (!head) {
        head = tail = newNode;
    }
    else {
        Node* current = head;
        Node* prev = nullptr;

        while (current && current->hashValue < hashedFirstData) {
            prev = current;
            current = current->next;
        }

        if (!prev) {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        else if (!current) {
            prev->next = newNode;
            newNode->prev = prev;
            tail = newNode;
        }
        else {
            prev->next = newNode;
            newNode->prev = prev;
            newNode->next = current;
            current->prev = newNode;
        }
    }

    dataList.push_back(newNode);
    dataHashMap.insert({ hashedFirstData, newNode });
}



void ListaDoble::printList() {
    Node* current = head;
    while (current) {
        std::cout << "Data: " << current->data << ", Hash: " << current->hashValue << std::endl;
        std::cout << std::endl;
        current = current->next;
    }
    std::cout << std::endl;
}

void ListaDoble::deleteList() {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

std::string ListaDoble::funcionhash(const std::string str) {

    std::hash<std::string> hashFunction;

    size_t hashValue = hashFunction(str);

    std::stringstream ss;
    ss << std::hex << std::setw(10) << std::setfill('0') << hashValue;
    std::string truncatedHash = ss.str().substr(0, 10);


    //std::cout << "Valor hash truncado de \"" << str << "\": " << truncatedHash << std::endl;

    return truncatedHash;
}

Node* ListaDoble::buscarPorLlave(const std::string& llaveBuscada) {
    std::string hashedLlaveBuscada = funcionhash(llaveBuscada);


    auto range = dataHashMap.equal_range(hashedLlaveBuscada);

    if (range.first != dataHashMap.end()) {

        return range.first->second;
    }
    else {
        return nullptr;
    }
}

void ListaDoble::mostrarResultados(Node* resultado) {
    if (resultado == nullptr) {
        std::cout << "No se encontraron resultados." << std::endl;
    }
    else {
        std::cout << "Resultados encontrados:" << std::endl;
        auto range = dataHashMap.equal_range(resultado->hashValue);
        for (auto it = range.first; it != range.second; ++it) {
            Node* actual = it->second;
            std::cout << "Clave original: " << actual->originalData
                << ", Hash: " << actual->originalData
                << ", Set completo: " << actual->originalData << ","
                << actual->campo2 << std::endl;
        }
    }
}


void ListaDoble::searchByKey(const std::string& searchTerm) {
    std::string hashedSearchTerm = funcionhash(searchTerm);

    auto range = dataHashMap.equal_range(hashedSearchTerm);


    for (auto it = range.first; it != range.second; ++it) {
        std::cout << "Clave original: " << searchTerm << ", Hash: " << it->second->hashValue << ", Set completo: " << it->second->data << std::endl;
    }

    if (range.first == dataHashMap.end()) {
        std::cout << "No se encontraron resultados para la clave: " << searchTerm << std::endl;
    }
}





void ListaDoble::searchByValue(const std::string& searchTerm) {
    for (const auto& pair : dataHashMap) {
        auto range = dataHashMap.equal_range(pair.first);

        for (auto it = range.first; it != range.second; ++it) {
            const Node* currentNode = it->second;

            while (currentNode != nullptr) {

                if (busquedaSecuencial(currentNode->data, searchTerm)) {
                    std::cout << "Valor encontrado en conjunto de datos " << pair.first << ": "
                        << "Clave: " << currentNode->originalData << ", "
                        << "Valor: " << currentNode->data << ", "
                        << "Hash: " << currentNode->hashValue << ", "
                        << "Set completo: " << currentNode->data << ","
                        << currentNode->campo2 << std::endl;
                }

                currentNode = currentNode->next;
            }
        }
    }
}


bool ListaDoble::busquedaSecuencial(const std::string& data, const std::string& searchTerm) {

    size_t pos = data.find(searchTerm);
    return pos != std::string::npos;
}



