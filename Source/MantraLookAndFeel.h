#pragma once

#include <juce_gui_basics/juce_gui_basics.h>

class MantraLookAndFeel : public juce::LookAndFeel_V4
{
public:
    inline static const juce::Colour amber{0xffe8a33d};
    inline static const juce::Colour panelFill{0xff1d1d24};
    inline static const juce::Colour panelOutline{0xff2c2c35};
    inline static const juce::Colour textDim{0xff8a8a94};

    MantraLookAndFeel()
    {
        setColour(juce::Slider::textBoxTextColourId, juce::Colour(0xffb8b8c0));
        setColour(juce::Slider::textBoxOutlineColourId, juce::Colours::transparentBlack);
        setColour(juce::Slider::textBoxBackgroundColourId, juce::Colours::transparentBlack);
        setColour(juce::Label::textColourId, juce::Colour(0xffcacad2));
        setColour(juce::TextButton::buttonColourId, juce::Colour(0xff2a2a32));
        setColour(juce::TextButton::buttonOnColourId, amber);
        setColour(juce::TextButton::textColourOffId, amber);
        setColour(juce::ComboBox::outlineColourId, panelOutline);
    }

    void drawRotarySlider(juce::Graphics& g, int x, int y, int width, int height,
                          float sliderPos, float rotaryStartAngle, float rotaryEndAngle,
                          juce::Slider&) override
    {
        auto bounds = juce::Rectangle<float>((float)x, (float)y, (float)width, (float)height).reduced(4.0f);
        auto radius = juce::jmin(bounds.getWidth(), bounds.getHeight()) / 2.0f;
        auto centre = bounds.getCentre();
        auto angle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);
        auto arcRadius = radius - 3.0f;
        juce::PathStrokeType stroke(4.0f, juce::PathStrokeType::curved, juce::PathStrokeType::rounded);

        // Track arc
        juce::Path track;
        track.addCentredArc(centre.x, centre.y, arcRadius, arcRadius, 0.0f,
                            rotaryStartAngle, rotaryEndAngle, true);
        g.setColour(juce::Colour(0xff26262e));
        g.strokePath(track, stroke);

        // Value arc
        juce::Path value;
        value.addCentredArc(centre.x, centre.y, arcRadius, arcRadius, 0.0f,
                            rotaryStartAngle, angle, true);
        g.setColour(amber);
        g.strokePath(value, stroke);

        // Knob body with drop shadow and vertical sheen
        auto knobRadius = arcRadius - 8.0f;
        auto knobRect = juce::Rectangle<float>(knobRadius * 2.0f, knobRadius * 2.0f).withCentre(centre);

        g.setColour(juce::Colours::black.withAlpha(0.4f));
        g.fillEllipse(knobRect.translated(0.0f, 2.0f));

        g.setGradientFill(juce::ColourGradient(juce::Colour(0xff3e3e48), centre.x, knobRect.getY(),
                                               juce::Colour(0xff1c1c22), centre.x, knobRect.getBottom(),
                                               false));
        g.fillEllipse(knobRect);

        g.setColour(juce::Colour(0xff56565f));
        g.drawEllipse(knobRect, 1.2f);

        // Pointer
        juce::Path pointer;
        pointer.addRoundedRectangle(-2.0f, -knobRadius + 4.0f, 4.0f, knobRadius * 0.42f, 2.0f);
        pointer.applyTransform(juce::AffineTransform::rotation(angle).translated(centre.x, centre.y));
        g.setColour(amber);
        g.fillPath(pointer);
    }
};
