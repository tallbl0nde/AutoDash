#ifndef INTERFACE_ICONFIG_HPP
#define INTERFACE_ICONFIG_HPP

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
        std::vector<std::pair<StringHandler, InvokeRequest>> backgroundImageFilePathHandlers;

        // Event handlers to invoke when resourcesFolderPath is changed.
        std::vector<std::pair<StringHandler, InvokeRequest>> resourcesFolderPathHandlers;

        // Event handlers to invoke when fontFamily is changed.
        std::vector<std::pair<StringHandler, InvokeRequest>> fontFamilyHandlers;

        // Event handlers to invoke when fontSize is changed.
        std::vector<std::pair<IntHandler, InvokeRequest>> fontSizeHandlers;

        // Event handlers to invoke when backgroundColour is changed.
        std::vector<std::pair<ColourHandler, InvokeRequest>> backgroundColourHandlers;

        // Event handlers to invoke when mainTextColour is changed.
        std::vector<std::pair<ColourHandler, InvokeRequest>> mainTextColourHandlers;

    protected:
        // --- EVENT RAISERS ---

        // Raises the BackgroundImageFilePathChanged event.
        void raiseBackgroundImageFilePathChanged(const std::string str) {
            for (auto & entry : this->backgroundImageFilePathHandlers) {
                if (entry.second()) {
                    entry.first(str);
                }
            }
        }

        // Raises the ResourcesFolderPathChanged event.
        void raiseResourcesFolderPathChanged(const std::string str) {
            for (auto & entry : this->resourcesFolderPathHandlers) {
                if (entry.second()) {
                    entry.first(str);
                }
            }
        }

        // Raises the FontFamilyChanged event.
        void raiseFontFamilyChanged(const std::string str) {
            for (auto & entry : this->fontFamilyHandlers) {
                if (entry.second()) {
                    entry.first(str);
                }
            }
        }

        // Raises the FontSizeChanged event.
        void raiseFontSizeChanged(const int value) {
            for (auto & entry : this->fontSizeHandlers) {
                if (entry.second()) {
                    entry.first(value);
                }
            }
        }

        // Raises the BackgroundColourChanged event.
        void raiseBackgroundColourChanged(const Colour colour) {
            for (auto & entry : this->backgroundColourHandlers) {
                if (entry.second()) {
                    entry.first(colour);
                }
            }
        }

        // Raises the MainTextColourChanged event.
        void raiseMainTextColourChanged(const Colour colour) {
            for (auto & entry : this->mainTextColourHandlers) {
                if (entry.second()) {
                    entry.first(colour);
                }
            }
        }

    public:
        // --- CONFIG VALUES ---

        // Returns the path to the image to be used as a background.
        virtual std::string backgroundImageFilePath() = 0;
        // Sets the path to the image to be used as a background.
        virtual bool setBackgroundImageFilePath(const std::string) = 0;

        // Gets the resources folder path.
        virtual std::string resourcesFolderPath() = 0;
        // Sets the resources folder path.
        virtual bool setResourcesFolderPath(const std::string) = 0;

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

        // Returns the backgrounds folder path.
        std::string backgroundsFolderPath() {
           return this->resourcesFolderPath() + "/backgrounds/";
        }

        // Returns the fonts folder path.
        std::string fontsFolderPath() {
            return this->resourcesFolderPath() + "/fonts/";
        }

        // Returns the icons folder path.
        std::string iconsFolderPath() {
            return this->resourcesFolderPath() + "/icons/";
        }

        // Destroys the IConfig object.
        virtual ~IConfig() {

        }

        // --- EVENT HANDLER REGISTRATIONS ---

        // Registers an event handler with the BackgroundImageFilePathChanged event.
        void onBackgroundImageFilePathChanged(const StringHandler & handler, const InvokeRequest & canInvoke) {
            this->backgroundImageFilePathHandlers.push_back(std::make_pair(handler, canInvoke));
        }

        // Registers an event handler with the ResourcesFolderPathChanged event.
        void onResourcesFolderPathChanged(const StringHandler & handler, const InvokeRequest & canInvoke) {
            this->resourcesFolderPathHandlers.push_back(std::make_pair(handler, canInvoke));
        }

        // Registers an event handler with the FontFamilyChanged event.
        void onFontFamilyChanged(const StringHandler & handler, const InvokeRequest & canInvoke) {
            this->fontFamilyHandlers.push_back(std::make_pair(handler, canInvoke));
        }

        // Registers an event handler with the FontSizeChanged event.
        void onFontSizeChanged(const IntHandler & handler, const InvokeRequest & canInvoke) {
            this->fontSizeHandlers.push_back(std::make_pair(handler, canInvoke));
        }

        // Registers an event handler with the BackgroundColourChanged event.
        void onBackgroundColourChanged(const ColourHandler & handler, const InvokeRequest & canInvoke) {
            this->backgroundColourHandlers.push_back(std::make_pair(handler, canInvoke));
        }

        // Registers an event handler with the MainTextColourChanged event.
        void onMainTextColourChanged(const ColourHandler & handler, const InvokeRequest & canInvoke) {
            this->mainTextColourHandlers.push_back(std::make_pair(handler, canInvoke));
        }
};

#endif
