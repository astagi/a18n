a18n
====
i18n library for Arduino

Usage
-----
a18n is a small library to manage i18n on your Arduino projects. It accepts a json string in this format:
```
{
    "item_id": {
        "language_code_1":"translation_1", 
        "language_code_2":"translation_2", 
        ...
        "language_code_N":"translation_N"
    }
}
```
For example:
```
#include <a18n.h>
char* data = "{\"limit\":{\"en\":\"Limit\",\"it\":\"Limite\"}}";
a18n imanager = new a18n("en", data);
imanager->getTranslation("limit"); //will return "Limit"
```
-------
Relased under MIT license, Copyright (c) 2013 Andrea Stagi <stagi.andrea@gmail.com>
