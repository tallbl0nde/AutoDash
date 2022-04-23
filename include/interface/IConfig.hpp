#ifndef INTERFACE_ICONFIG_HPP
#define INTERFACE_ICONFIG_HPP

#include <algorithm>
#include <functional>
#include <string>
#include <vector>

// 'Interface' for config classes.
class IConfig {
    public:
        // --- TYPES ---

        // RGBA colour
        struct Colour {
            short r;      // Red
            short g;      // Green
            short b;      // Blue
            short a;      // Alpha
        };

        // --- TYPEDEFS ---

        typedef std::function<bool()> InvokeRequest;
        typedef std::function<void(const Colour)> ColourHandler;
        typedef std::function<void(const int)> IntHandler;
        typedef std::function<void(const std::string)> StringHandler;

    private:
        // --- EVENT HANDLERS ---

        // Event handlers to invoke when backgroundImageFilePath is changed.
        std::vector<std::tuple<std::string, StringHandler, InvokeRequest>> backgroundImageFilePathHandlers;

        // Event handlers to invoke when modulesFolderPath is changed.
        std::vector<std::tuple<std::string, StringHandler, InvokeRequest>> modulesFolderPathHandlers;

        // Event handlers to invoke when fontFamily is changed.
        std::vector<std::tuple<std::string, StringHandler, InvokeRequest>> fontFamilyHandlers;

        // Event handlers to invoke when fontSize is changed.
        std::vector<std::tuple<std::string, IntHandler, InvokeRequest>> fontSizeHandlers;

        // Event handlers to invoke when backgroundColour is changed.
        std::vector<std::tuple<std::string, ColourHandler, InvokeRequest>> backgroundColourHandlers;

        // Event handlers to invoke when mainTextColour is changed.
        std::vector<std::tuple<std::string, ColourHandler, InvokeRequest>> mainTextColourHandlers;

    protected:
        // --- EVENT RAISERS ---

        // Raises the BackgroundImageFilePathChanged event.
        void raiseBackgroundImageFilePathChanged(const std::string str) {
            for (auto & entry : this->backgroundImageFilePathHandlers) {
                if (std::get<2>(entry)) {
                    std::get<1>(entry)(str);
                }
            }
        }

        // Raises the ModulesFolderPathChanged event.
        void raiseModulesFolderPathChanged(const std::string str) {
            for (auto & entry : this->modulesFolderPathHandlers) {
                if (std::get<2>(entry)) {
                    std::get<1>(entry)(str);
                }
            }
        }

        // Raises the FontFamilyChanged event.
        void raiseFontFamilyChanged(const std::string str) {
            for (auto & entry : this->fontFamilyHandlers) {
                if (std::get<2>(entry)) {
                    std::get<1>(entry)(str);
                }
            }
        }

        // Raises the FontSizeChanged event.
        void raiseFontSizeChanged(const int value) {
            for (auto & entry : this->fontSizeHandlers) {
                if (std::get<2>(entry)) {
                    std::get<1>(entry)(value);
                }
            }
        }

        // Raises the BackgroundColourChanged event.
        void raiseBackgroundColourChanged(const Colour colour) {
            for (auto & entry : this->backgroundColourHandlers) {
                if (std::get<2>(entry)) {
                    std::get<1>(entry)(colour);
                }
            }
        }

        // Raises the MainTextColourChanged event.
        void raiseMainTextColourChanged(const Colour colour) {
            for (auto & entry : this->mainTextColourHandlers) {
                if (std::get<2>(entry) ) {
                    std::get<1>(entry)(colour);
                }
            }
        }

    public:
        // --- CONFIG VALUES ---

        // Returns the path to the image to be used as a background.
        virtual std::string backgroundImageFilePath() = 0;
        // Sets the path to the image to be used as a background.
        virtual bool setBackgroundImageFilePath(const std::string) = 0;

        // Gets the modules folder path.
        virtual std::string modulesFolderPath() = 0;
        // Sets the modules folder path.
        virtual bool setModulesFolderPath(const std::string) = 0;

        // Returns the font family to use.
        virtual std::string fontFamily() = 0;
        // Sets the font family to use.
        virtual bool setFontFamily(const std::string) = 0;

        // Returns the font size to use.
        virtual int fontSize() = 0;
        // Sets the font size to use.
        virtual bool setFontSize(const int) = 0;

        // Returns the background colour to use for elements.
        virtual Colour backgroundColour() = 0;
        // Sets the background colour to use for elements.
        virtual bool setBackgroundColour(const Colour) = 0;

        // Returns the main text colour.
        virtual Colour mainTextColour() = 0;
        // Sets the main text colour.
        virtual bool setMainTextColour(const Colour) = 0;

        // --- AGGREGATE VALUES ---

        // Destroys the IConfig object.
        virtual ~IConfig() {}

        // --- EVENT HANDLER REGISTRATIONS ---

        // Registers an event handler with the BackgroundImageFilePathChanged event.
        void onBackgroundImageFilePathChanged(const std::string & identifier, const StringHandler & handler, const InvokeRequest & canInvoke) {
            if (handler == nullptr || canInvoke == nullptr) {
                this->backgroundImageFilePathHandlers.erase(std::remove_if(this->backgroundImageFilePathHandlers.begin(), this->backgroundImageFilePathHandlers.end(), [identifier](const std::tuple<std::string, StringHandler, InvokeRequest> & entry) {
                    return std::get<0>(entry) == identifier;
                }));
            }

            this->backgroundImageFilePathHandlers.push_back(std::make_tuple(identifier, handler, canInvoke));
        }

        // Registers an event handler with the ModulesFolderPathChanged event.
        void onModulesFolderPathChanged(const std::string & identifier, const StringHandler & handler, const InvokeRequest & canInvoke) {
            if (handler == nullptr || canInvoke == nullptr) {
                this->modulesFolderPathHandlers.erase(std::remove_if(this->modulesFolderPathHandlers.begin(), this->modulesFolderPathHandlers.end(), [identifier](const std::tuple<std::string, StringHandler, InvokeRequest> & entry) {
                    return std::get<0>(entry) == identifier;
                }));
            }

            this->modulesFolderPathHandlers.push_back(std::make_tuple(identifier, handler, canInvoke));
        }

        // Registers an event handler with the FontFamilyChanged event.
        void onFontFamilyChanged(const std::string & identifier, const StringHandler & handler, const InvokeRequest & canInvoke) {
            if (handler == nullptr || canInvoke == nullptr) {
                this->fontFamilyHandlers.erase(std::remove_if(this->fontFamilyHandlers.begin(), this->fontFamilyHandlers.end(), [identifier](const std::tuple<std::string, StringHandler, InvokeRequest> & entry) {
                    return std::get<0>(entry) == identifier;
                }));
            }

            this->fontFamilyHandlers.push_back(std::make_tuple(identifier, handler, canInvoke));
        }

        // Registers an event handler with the FontSizeChanged event.
        void onFontSizeChanged(const std::string & identifier, const IntHandler & handler, const InvokeRequest & canInvoke) {
            if (handler == nullptr || canInvoke == nullptr) {
                this->fontSizeHandlers.erase(std::remove_if(this->fontSizeHandlers.begin(), this->fontSizeHandlers.end(), [identifier](const std::tuple<std::string, IntHandler, InvokeRequest> & entry) {
                    return std::get<0>(entry) == identifier;
                }));
            }

            this->fontSizeHandlers.push_back(std::make_tuple(identifier, handler, canInvoke));
        }

        // Registers an event handler with the BackgroundColourChanged event.
        void onBackgroundColourChanged(const std::string & identifier, const ColourHandler & handler, const InvokeRequest & canInvoke) {
            if (handler == nullptr || canInvoke == nullptr) {
                this->backgroundColourHandlers.erase(std::remove_if(this->backgroundColourHandlers.begin(), this->backgroundColourHandlers.end(), [identifier](const std::tuple<std::string, ColourHandler, InvokeRequest> & entry) {
                    return std::get<0>(entry) == identifier;
                }));
            }

            this->backgroundColourHandlers.push_back(std::make_tuple(identifier, handler, canInvoke));
        }

        // Registers an event handler with the MainTextColourChanged event.
        void onMainTextColourChanged(const std::string & identifier, const ColourHandler & handler, const InvokeRequest & canInvoke) {
            if (handler == nullptr || canInvoke == nullptr) {
                this->mainTextColourHandlers.erase(std::remove_if(this->mainTextColourHandlers.begin(), this->mainTextColourHandlers.end(), [identifier](const std::tuple<std::string, ColourHandler, InvokeRequest> & entry) {
                    return std::get<0>(entry) == identifier;
                }));
            }

            this->mainTextColourHandlers.push_back(std::make_tuple(identifier, handler, canInvoke));
        }
};

#endif
