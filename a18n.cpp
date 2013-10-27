#include "a18n.h"
#include "aJSON.h"

a18n::a18n() {}

a18n::a18n(char* data) {
    setData(data);
}

a18n::a18n(char* locale, char* data) {
    this->locale = locale;
    setData(data);
}

void a18n::setData(char* data) {
    this->data = data;
    if (this->root)
        aJson.deleteItem(root);
    this->root = NULL;
}

void a18n::setLocale(char* locale) {
    this->locale = locale;
}

const char* a18n::getLocale() {
    return locale;
}

const char* a18n::getTranslation(char* item) {
    getTranslation(locale, item);
}

const char* a18n::getTranslation(char* locale, char* item) {
    if (root == NULL)
        root = aJson.parse(this->data);
    if (root != NULL) {
        aJsonObject* jitem = aJson.getObjectItem(root, item);
        if (item != NULL) {
            aJsonObject* jtranslation = aJson.getObjectItem(jitem, locale);
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
