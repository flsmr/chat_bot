#ifndef CHATBOT_H_
#define CHATBOT_H_

#include <wx/bitmap.h>
#include <string>
#include <iostream>

class GraphNode; // forward declaration
class ChatLogic; // forward declaration

class ChatBot
{
private:
    // data handles (owned)
    wxBitmap *_image; // avatar image

    // data handles (not owned)
    GraphNode *_currentNode;
    GraphNode *_rootNode;
    ChatLogic *_chatLogic;

    // proprietary functions
    int ComputeLevenshteinDistance(std::string s1, std::string s2);

public:
    // constructors / destructors
    ChatBot();                     // constructor WITHOUT memory allocation
    ChatBot(std::string filename); // constructor WITH memory allocation
    ~ChatBot();

    //// STUDENT CODE
    ////
    // Copy Constructor 
    ChatBot (const ChatBot &source_chatbot) 
    {
        std::cout << "ChatBot Copy Constructor" << std::endl;

        _chatLogic = source_chatbot._chatLogic;
        //_chatLogic->SetChatbotHandle(this);

        _rootNode = source_chatbot._rootNode;

        //_image = new wxBitmap();  
        _image = source_chatbot._image;

    }
    // Copy Assign Constructor
    ChatBot &operator=(const ChatBot &source_chatbot)
    {
        std::cout << "ChatBot Copy Assign Constructor" << std::endl;

        if (this == &source_chatbot)
            return *this;
        
        _chatLogic = source_chatbot._chatLogic;
        _rootNode = source_chatbot._rootNode;
        _image = source_chatbot._image;

        return *this;
    }

    // Move Constructor 
    ChatBot(ChatBot &&source_chatbot)
    {
        std::cout << "ChatBot Move Constructor" << std::endl;

        _chatLogic = source_chatbot._chatLogic;
        _rootNode = source_chatbot._rootNode;
        _image = source_chatbot._image;

        // clean up source
        source_chatbot._chatLogic = nullptr;
        source_chatbot._rootNode = nullptr; 
        delete source_chatbot._image;
        source_chatbot._image = NULL;
    }

    // Move Assign Constructor 
    ChatBot &operator=(ChatBot &&source_chatbot)
    {
        std::cout << "ChatBot Move Assignment Constructor" << std::endl;

        if (this == &source_chatbot)
            return *this;

        _chatLogic = source_chatbot._chatLogic;
        _rootNode = source_chatbot._rootNode;
        _image = source_chatbot._image;

        // clean up source
        source_chatbot._chatLogic = nullptr;
        source_chatbot._rootNode = nullptr; 
        delete source_chatbot._image;
        source_chatbot._image = NULL;

        return *this;
    }    
    ////
    //// EOF STUDENT CODE

    // getters / setters
    void SetCurrentNode(GraphNode *node);
    void SetRootNode(GraphNode *rootNode) { _rootNode = rootNode; }
    void SetChatLogicHandle(ChatLogic *chatLogic) { _chatLogic = chatLogic; }
    wxBitmap *GetImageHandle() { return _image; }

    // communication
    void ReceiveMessageFromUser(std::string message);
};

#endif /* CHATBOT_H_ */