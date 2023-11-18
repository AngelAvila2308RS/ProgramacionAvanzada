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

    if (dataHashMap.find(hashedFirstData) != dataHashMap.end()) {
        std::cerr << "Error: Nodo duplicado encontrado. Ignorando." << std::endl;
        return;
    }

    Node* newNode = new Node{ hashedFirstData, nullptr, nullptr };

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
    newNode->hashValue = funcionhash(newNode->data);

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
        const Node* currentNode = pair.second;

        while (currentNode != nullptr) {
            if (currentNode->data == searchTerm) {
                std::cout << "Valor encontrado: " << currentNode->data << ", Clave: " << pair.first << std::endl;
            }
            currentNode = currentNode->next;
        }
    }
}




