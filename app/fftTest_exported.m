classdef fftTest_exported < matlab.apps.AppBase

  % Properties that correspond to app components
  properties (Access = public)
    UIFigure     matlab.ui.Figure
    GridLayout   matlab.ui.container.GridLayout
    LeftPanel    matlab.ui.container.Panel
    Slider       matlab.ui.control.Slider
    SliderLabel  matlab.ui.control.Label
    RightPanel   matlab.ui.container.Panel
    UIAxes       matlab.ui.control.UIAxes
  end

  % Properties that correspond to apps with auto-reflow
  properties (Access = private)
    onePanelWidth = 576;
  end

  % Callbacks that handle component events
  methods (Access = private)

    % Value changed function: Slider
    function whogi(app, event)
      
      Fc = app.Slider.Value;
      Fs = 2048;
      delta = 2.0 * pi * (Fc/Fs);
      angle_ = delta * (0:4096);
      sig_ = cos(angle_) + sin(angle_)*1i;
      frq_ = fftshift(abs(fft(sig_)));
      plot(app.UIAxes, frq_)
      axis(app.UIAxes,[0 4096 0 5000])

    end

    % Changes arrangement of the app based on UIFigure width
    function updateAppLayout(app, event)
      currentFigureWidth = app.UIFigure.Position(3);
      if(currentFigureWidth <= app.onePanelWidth)
          % Change to a 2x1 grid
          app.GridLayout.RowHeight = {225, 225};
          app.GridLayout.ColumnWidth = {'1x'};
          app.RightPanel.Layout.Row = 2;
          app.RightPanel.Layout.Column = 1;
      else
          % Change to a 1x2 grid
          app.GridLayout.RowHeight = {'1x'};
          app.GridLayout.ColumnWidth = {231, '1x'};
          app.RightPanel.Layout.Row = 1;
          app.RightPanel.Layout.Column = 2;
      end
    end
  end

  % Component initialization
  methods (Access = private)

    % Create UIFigure and components
    function createComponents(app)

      % Create UIFigure and hide until all components are created
      app.UIFigure = uifigure('Visible', 'off');
      app.UIFigure.AutoResizeChildren = 'off';
      app.UIFigure.Position = [100 100 912 225];
      app.UIFigure.Name = 'MATLAB App';
      app.UIFigure.SizeChangedFcn = createCallbackFcn(app, @updateAppLayout, true);

      % Create GridLayout
      app.GridLayout = uigridlayout(app.UIFigure);
      app.GridLayout.ColumnWidth = {231, '1x'};
      app.GridLayout.RowHeight = {'1x'};
      app.GridLayout.ColumnSpacing = 0;
      app.GridLayout.RowSpacing = 0;
      app.GridLayout.Padding = [0 0 0 0];
      app.GridLayout.Scrollable = 'on';

      % Create LeftPanel
      app.LeftPanel = uipanel(app.GridLayout);
      app.LeftPanel.Layout.Row = 1;
      app.LeftPanel.Layout.Column = 1;

      % Create SliderLabel
      app.SliderLabel = uilabel(app.LeftPanel);
      app.SliderLabel.HorizontalAlignment = 'right';
      app.SliderLabel.Position = [7 188 36 22];
      app.SliderLabel.Text = 'Slider';

      % Create Slider
      app.Slider = uislider(app.LeftPanel);
      app.Slider.Limits = [-1024 1024];
      app.Slider.ValueChangedFcn = createCallbackFcn(app, @whogi, true);
      app.Slider.Step = 2;
      app.Slider.Position = [65 197 150 3];

      % Create RightPanel
      app.RightPanel = uipanel(app.GridLayout);
      app.RightPanel.Layout.Row = 1;
      app.RightPanel.Layout.Column = 2;

      % Create UIAxes
      app.UIAxes = uiaxes(app.RightPanel);
      title(app.UIAxes, 'Title')
      xlabel(app.UIAxes, 'X')
      ylabel(app.UIAxes, 'Y')
      zlabel(app.UIAxes, 'Z')
      app.UIAxes.Position = [40 25 599 185];

      % Show the figure after all components are created
      app.UIFigure.Visible = 'on';
    end
  end

  % App creation and deletion
  methods (Access = public)

    % Construct app
    function app = fftTest_exported

      % Create UIFigure and components
      createComponents(app)

      % Register the app with App Designer
      registerApp(app, app.UIFigure)

      if nargout == 0
        clear app
      end
    end

    % Code that executes before app deletion
    function delete(app)

      % Delete UIFigure when app is deleted
      delete(app.UIFigure)
    end
  end
end