#ifndef RESOURCEHOLDERS_FONTHOLDER_H
#define RESOURCEHOLDERS_FONTHOLDER_H

#include "ResourceIdentifiers.h"

#include "raylib.h"

#include <map>
#include <memory>
#include <string>

// Singleton
class FontHolder {
public:
    static const int MAX_SIZE = 100;
    static const int ROUNDING = 20; // Save loading time
    static const int VN_CODEPOINTS[];

public:
    static FontHolder& getInstance();

    static void load(FontID id, const std::string& filename);

    static Font& get(FontID id, int size);

private:
    FontHolder();
    FontHolder(FontHolder const&) = delete;
    void operator= (FontHolder const&) = delete;
    ~FontHolder();

    std::map<FontID, std::unique_ptr<Font>> mResourceMap[MAX_SIZE + 1];

private:
    void insertResource(int size, FontID id, std::unique_ptr<Font> resource);

    void loadHelper(FontID id, const std::string& filename);

    Font& getHelper(FontID id, int size);
    const Font& getHelper(FontID id, int size) const;
};

#endif // RESOURCEHOLDERS_FONTHOLDER_H
