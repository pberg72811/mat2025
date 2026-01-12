fig = uifigure();
textArea = uitextarea(fig);

tObj = timer("TimerFcn",@doThis);
tObj.ExecutionMode = "fixedRate";
tObj.Period = 1;
tObj.TasksToExecute = 3;
tObj.start


function doThis(thisThing, thisEvent)
%disp(thisThing);
disp(thisEvent.Data.time);
disp("H")
end
% classdef comp1_exported < matlab.ui.componentcontainer.ComponentContainer
% 
%   % Properties that correspond to underlying components
%   properties (Access = private, Transient, NonCopyable)
%     GridLayout           matlab.ui.container.GridLayout
%     POSIXEditField       matlab.ui.control.NumericEditField
%     POSIXEditFieldLabel  matlab.ui.control.Label
%   end
% 
%   methods (Access = protected)
% 
%     % Code that executes when the value of a property is changed
%     function update(comp)
%       % Use this function to update the underlying components
% 
%     end
% 
%     % Create the underlying components
%     function setup(comp)
% 
%       comp.Position = [1 1 523 90];
% 
%       % Create GridLayout
%       comp.GridLayout = uigridlayout(comp);
%       comp.GridLayout.ColumnWidth = {'0.2x', '1x'};
% 
%       % Create POSIXEditFieldLabel
%       comp.POSIXEditFieldLabel = uilabel(comp.GridLayout);
%       comp.POSIXEditFieldLabel.HorizontalAlignment = 'center';
%       comp.POSIXEditFieldLabel.Layout.Row = 1;
%       comp.POSIXEditFieldLabel.Layout.Column = 1;
%       comp.POSIXEditFieldLabel.Text = 'POSIX';
% 
%       % Create POSIXEditField
%       comp.POSIXEditField = uieditfield(comp.GridLayout, 'numeric');
%       comp.POSIXEditField.Layout.Row = 1;
%       comp.POSIXEditField.Layout.Column = 2;
%     end
%   end
% end