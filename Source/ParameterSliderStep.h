/*
  ==============================================================================

    ParameterSliderStep.h
    Created: 18 Mar 2016 1:06:40pm
    Author:  John Flynn

  ==============================================================================
*/

#ifndef PARAMETERSLIDERSTEP_H_INCLUDED
#define PARAMETERSLIDERSTEP_H_INCLUDED

#include "ParameterSlider.h"


//==============================================================================
/**
    Subclass of ParameterSlider that allows stepped controls when used in 
    conjunction with AudioParameterFloatStep
*/
class ParameterSliderStep   : public ParameterSlider
{
public:
    ParameterSliderStep (AudioProcessorParameter& p)
        : ParameterSlider (p)
    {
        jassert (p.getNumSteps() > 0);  // Ensure this is stepped parameter
                                        // (getNumSteps() gives -2147483648 if
                                        // continuous.)

        const float normStepSize = 1.0 / p.getNumSteps();

        setRange (0.0, 1.0, normStepSize);  // override setRange continuous
                                            // in ParameterSlider xtor

        updateSliderPos();                  // update position
                                            // (timer already started in
                                            // ParameterSlider xtor)
    }

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ParameterSliderStep)
};


#endif  // PARAMETERSLIDERSTEP_H_INCLUDED
