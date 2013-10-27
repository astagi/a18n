#include "a18n.h"
#include "aJSON.h"

a18n::a18n() {}

a18n::a18n(char* data) {
    setData(data);
}

void a18n::setData(char* data) {
    this->data = data;
    if (this->root)
        aJson.deleteItem(root);
    this->root = NULL;
}

char* a18n::getTranslation(char* code, char* item) {
    if (root == NULL)
        root = aJson.parse(this->data);
    if (root != NULL) {
        aJsonObject* jitem = aJson.getObjectItem(root, item);
        if (item != NULL) {
            aJsonObject* jtranslation = aJson.getObjectItem(jitem, code);
            return jtranslation->valuestring;
        }
    }
}

a18n::~a18n() {
    if (data)
        delete(data);
    if (root)
        aJson.deleteItem(root);
}
