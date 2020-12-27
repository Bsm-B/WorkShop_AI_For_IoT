# TensorFlow-Lite For ESP32

This repo demonstrates how to use a TensorFlow model on the ESP32 using Platform.io.


Open up the `train_model` notebook and follow the instructions in the notebook.

Once you've trained and converted the model run:

```
xxd -i converted_model.tflite > firmware/src/model_data.cc
```

You can then open up the platform.io project in `firmware` folder and try it out.
