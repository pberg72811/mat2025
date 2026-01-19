classdef First_Live_Task < matlab.task.LiveTask
  properties(Access = private, Transient)
    SliderLabel matlab.ui.control.Label
    Slider matlab.ui.control.Slider
    SliderHelper matlab.ui.control.NumericEditField
    SliderLabel1 matlab.ui.control.Label
    Slider1 matlab.ui.control.Slider
    Slider1Helper matlab.ui.control.NumericEditField
  end

  properties(Dependent)
    State
    Summary
  end

  methods(Access = protected)
    function setup(task)
      createComponents(task);
    end
  end

  methods
    function createComponents(task)
      grid = uigridlayout(task.LayoutManager);
      grid.RowHeight = repmat({'fit'}, 1, 2);
      grid.ColumnWidth = repmat({'fit'}, 1, 2);

      % Create SliderLabel
      task.SliderLabel = uilabel(grid, 'Text', 'Slider');
      task.SliderLabel.Layout.Row = 1;
      task.SliderLabel.Layout.Column = 1;

      % Create Slider
      nestedGrid = uigridlayout(grid);
      nestedGrid.Layout.Row = 1;
      nestedGrid.Layout.Column = 2;
      nestedGrid.ColumnWidth = {'1x', 40};
      nestedGrid.RowHeight = {'1x'};
      nestedGrid.ColumnSpacing = 5;
      nestedGrid.RowSpacing = 0;
      nestedGrid.Padding = [0 0 0 0];
      task.Slider = uislider(nestedGrid);
      task.Slider.Layout.Row = 1;
      task.Slider.Layout.Column = 1;
      task.Slider.Limits = [1 100];
      task.Slider.Value = 1;
      task.Slider.MajorTicks = [];
      task.Slider.MinorTicks = [];
      task.Slider.Step = 5;
      task.Slider.ValueChangedFcn = @(app, event) set(task.SliderHelper, 'Value', event.Value);
      task.Slider.ValueChangingFcn = task.Slider.ValueChangedFcn;
      task.SliderHelper = uieditfield(nestedGrid, 'numeric');
      task.SliderHelper.Limits = task.Slider.Limits;
      task.SliderHelper.Value = task.Slider.Value;
      task.SliderHelper.Layout.Row = 1;
      task.SliderHelper.Layout.Column = 2;
      task.SliderHelper.ValueChangedFcn = @(app, event) set(task.Slider, 'Value', event.Value);

      % Create SliderLabel1
      task.SliderLabel1 = uilabel(grid, 'Text', 'r');
      task.SliderLabel1.Layout.Row = 2;
      task.SliderLabel1.Layout.Column = 1;

      % Create Slider1
      nestedGrid = uigridlayout(grid);
      nestedGrid.Layout.Row = 2;
      nestedGrid.Layout.Column = 2;
      nestedGrid.ColumnWidth = {'1x', 40};
      nestedGrid.RowHeight = {'1x'};
      nestedGrid.ColumnSpacing = 5;
      nestedGrid.RowSpacing = 0;
      nestedGrid.Padding = [0 0 0 0];
      task.Slider1 = uislider(nestedGrid);
      task.Slider1.Layout.Row = 1;
      task.Slider1.Layout.Column = 1;
      task.Slider1.Limits = [1 5];
      task.Slider1.Value = 1;
      task.Slider1.MajorTicks = [];
      task.Slider1.MinorTicks = [];
      task.Slider1.Step = 1;
      task.Slider1.ValueChangedFcn = @(app, event) set(task.Slider1Helper, 'Value', event.Value);
      task.Slider1.ValueChangingFcn = task.Slider1.ValueChangedFcn;
      task.Slider1Helper = uieditfield(nestedGrid, 'numeric');
      task.Slider1Helper.Limits = task.Slider1.Limits;
      task.Slider1Helper.Value = task.Slider1.Value;
      task.Slider1Helper.Layout.Row = 1;
      task.Slider1Helper.Layout.Column = 2;
      task.Slider1Helper.ValueChangedFcn = @(app, event) set(task.Slider1, 'Value', event.Value);
    end

    function [code,outputs] = generateCode(task)
      outputs = {'z'};
      codeTemplate = ["tree = @(c,x,r) cumsum(exp(1i*(c*x.*x + r)));"
        "c = pi*(1+sqrt(5))/2;"
        "npts = " + string(task.Slider.Value) + "* 100;"
        "x = 0:npts;"
        "r = " + string(task.Slider1.Value) + ";"
        "z = tree(c,x,r);"
        "clear c npts r tree x;"];
      code = join(string(codeTemplate), newline);
    end

    function summary = get.Summary(~)
      summary = "To test out live task";
    end

    function state = get.State(task)
      state = struct;
      state.Slider = task.Slider.Value;
      state.Slider1 = task.Slider1.Value;
    end

    function set.State(task, state)
      task.Slider.Value = state.Slider;
      task.SliderHelper.Value = state.Slider;
      task.Slider1.Value = state.Slider1;
      task.Slider1Helper.Value = state.Slider1;
    end

    function reset(task)
      task.Slider.Value = 1;
      task.SliderHelper.Value = 1;
      task.Slider1.Value = 1;
      task.Slider1Helper.Value = 1;
    end
  end



  methods(Access = private)
    function out = extractValue(~, widget)
      value = widget.Value;
      type = class(value);

      if isfield(widget.UserData, 'sourceLiveControlData')
        type = widget.UserData.sourceLiveControlData.valueType;
      end

      switch (type)
        case "string"
          out = append('"', replace(value, '"', '""'), '"');
        case "double"
          out = string(value);
        case "char"
          out = append("'", replace(value, "'", "''"), "'");
        otherwise
          out = value;
      end
    end
  end
end