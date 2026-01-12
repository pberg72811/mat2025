classdef launcher_exported < matlab.ui.componentcontainer.ComponentContainer

    % Properties that correspond to underlying components
    properties (Access = private, Transient, NonCopyable)
        GridLayout  matlab.ui.container.GridLayout
        Button004   matlab.ui.control.Button
        Button003   matlab.ui.control.Button
        Button002   matlab.ui.control.Button
        Button001   matlab.ui.control.Button
    end

    methods (Access = public)
        function comp = launcher_exported()
            set(comp.Parent, "Position", [680 458 320 240] );
        end
    end

    % Callbacks that handle component events
    methods (Access = private)

        % Button pushed function: Button001
        function Button001Pushed(comp, event)
            disp("HELLO 1");
        end

        % Button pushed function: Button002
        function Button002Pushed(comp, event)
            disp("HELLO 2");
        end

        % Button pushed function: Button003
        function Button003Pushed(comp, event)
            disp("HELLO 3");
        end

        % Button pushed function: Button004
        function Button004Pushed(comp, event)
            disp("HELLO 3");
        end
    end

    methods (Access = protected)
        
        % Code that executes when the value of a property is changed
        function update(comp)
            % Use this function to update the underlying components
            
        end

        % Create the underlying components
        function setup(comp)

            comp.Position = [1 1 320 240];

            % Create GridLayout
            comp.GridLayout = uigridlayout(comp);

            % Create Button001
            comp.Button001 = uibutton(comp.GridLayout, 'push');
            comp.Button001.ButtonPushedFcn = matlab.apps.createCallbackFcn(comp, @Button001Pushed, true);
            comp.Button001.Layout.Row = 1;
            comp.Button001.Layout.Column = 1;
            comp.Button001.Text = 'Button001';

            % Create Button002
            comp.Button002 = uibutton(comp.GridLayout, 'push');
            comp.Button002.ButtonPushedFcn = matlab.apps.createCallbackFcn(comp, @Button002Pushed, true);
            comp.Button002.Layout.Row = 1;
            comp.Button002.Layout.Column = 2;
            comp.Button002.Text = 'Button002';

            % Create Button003
            comp.Button003 = uibutton(comp.GridLayout, 'push');
            comp.Button003.ButtonPushedFcn = matlab.apps.createCallbackFcn(comp, @Button003Pushed, true);
            comp.Button003.Layout.Row = 2;
            comp.Button003.Layout.Column = 1;
            comp.Button003.Text = 'Button003';

            % Create Button004
            comp.Button004 = uibutton(comp.GridLayout, 'push');
            comp.Button004.ButtonPushedFcn = matlab.apps.createCallbackFcn(comp, @Button004Pushed, true);
            comp.Button004.Layout.Row = 2;
            comp.Button004.Layout.Column = 2;
            comp.Button004.Text = 'Button004';
        end
    end
end