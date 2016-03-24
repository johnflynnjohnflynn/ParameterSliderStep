
ParameterSliderStep
-------------------

### Dummy audio plugin expanding AudioParameterFloat and ParameterSlider classes to allow stepped controls

![ParameterSliderStep image](http://www.johnflynn.info/images/ParameterSliderStep.png)

AudioParameterFloatStep class: Allows stepped controls when used in conjunction with ParameterSliderStep. (Overrides getNumSteps() method.)

ParameterSliderStep class: Allows stepped controls when used in conjunction with AudioParameterFloatStep. Asserts a reasonable number of steps (otherwise just use ParameterSlider).

See [www.johnflynn.info](http://www.johnflynn.info/)
