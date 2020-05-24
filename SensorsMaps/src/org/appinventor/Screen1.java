package org.appinventor;
import com.google.appinventor.components.runtime.HandlesEventDispatching;
import com.google.appinventor.components.runtime.EventDispatcher;
import com.google.appinventor.components.runtime.Form;
import com.google.appinventor.components.runtime.Component;
import com.google.appinventor.components.runtime.Button;
class Screen1 extends Form implements HandlesEventDispatching {
  private Button Sensors;
  private Button Maps;
  protected void $define() {
    this.AlignHorizontal(3);
    this.AlignVertical(2);
    this.AppName("SensorsMaps");
    this.Icon("sensors.jpg");
    this.Title("Screen1");
    Sensors = new Button(this);
    Sensors.BackgroundColor(0xFF000000);
    Sensors.FontBold(true);
    Sensors.FontSize(18);
    Sensors.Height(-1025);
    Sensors.Width(-1033);
    Sensors.Image("sensors.jpg");
    Sensors.Text("Sensors");
    Sensors.TextColor(0xFFFFFF00);
    Maps = new Button(this);
    Maps.FontBold(true);
    Maps.FontSize(18);
    Maps.Height(-1020);
    Maps.Width(-1033);
    Maps.Image("maps.jpg");
    Maps.Text("Maps");
  }
  public boolean dispatchEvent(Component component, String componentName, String eventName, Object[] params){
    return false;
  }
}