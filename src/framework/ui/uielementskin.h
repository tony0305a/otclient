/* The MIT License
 *
 * Copyright (c) 2010 OTClient, https://github.com/edubart/otclient
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */


#ifndef UIELEMENTSKIN_H
#define UIELEMENTSKIN_H

#include <prerequisites.h>
#include <graphics/image.h>
#include <ui/uiconstants.h>

class UIElement;

class UIElementSkin
{
public:
    UIElementSkin(const std::string& name, UI::ElementType elementType) :
        m_name(name),
        m_elementType(elementType) { }
    UIElementSkin() : m_elementType(UI::Element) { }
    virtual ~UIElementSkin() { }

    /// Load the skin from a YAML node
    virtual void load(const YAML::Node& node);
    /// Apply the skin to an element
    virtual void apply(UIElement *element);
    /// Draw the skinned element
    virtual void draw(UIElement *element);

    const std::string& getName() const { return m_name; }
    const Size& getDefaultSize() const { return m_defaultSize; }
    UI::ElementType getElementType() const { return m_elementType; }
    ImagePtr getDefaultImage() const { return m_defaultImage; }

protected:
    ImagePtr loadImage(const YAML::Node& node);

private:
    std::string m_name;
    UI::ElementType m_elementType;
    Size m_defaultSize;
    ImagePtr m_defaultImage;
};

typedef boost::shared_ptr<UIElementSkin> UIElementSkinPtr;

#endif // UIELEMENTSKIN_H
