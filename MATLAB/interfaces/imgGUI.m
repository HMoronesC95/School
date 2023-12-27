function varargout = imgGUI(varargin)
% IMGGUI MATLAB code for imgGUI.fig
%      IMGGUI, by itself, creates a new IMGGUI or raises the existing
%      singleton*.
%
%      H = IMGGUI returns the handle to a new IMGGUI or the handle to
%      the existing singleton*.
%
%      IMGGUI('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in IMGGUI.M with the given input arguments.
%
%      IMGGUI('Property','Value',...) creates a new IMGGUI or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before imgGUI_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to imgGUI_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help imgGUI

% Last Modified by GUIDE v2.5 19-Aug-2021 13:44:37

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @imgGUI_OpeningFcn, ...
                   'gui_OutputFcn',  @imgGUI_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before imgGUI is made visible.
function imgGUI_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to imgGUI (see VARARGIN)

% Choose default command line output for imgGUI
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes imgGUI wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = imgGUI_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on button press in pushbutton1.
function pushbutton1_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
[im1, direc] = uigetfile({'*.bmp; *.jpg; *.png'});
pushbutton1 = strcat(direc, im1);
im=imread(pushbutton1);
axes(handles.pantalla);
imshow(im);
set(handles.pantalla,'UserData',im);
set(handles.pushbutton1,'Enable', 'off');

% --- Executes on button press in pushbutton2.
function pushbutton2_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
global modo;
im = get(handles.pantalla, 'UserData');
if modo == 1
    if length(size(im)) == 3
        im = rgb2gray(im);
    end
        axes(handles.procesada);
        imhist(im);  
end
if modo == 2
    sf=fspecial('laplacian',0);
    im2=imfilter(im,sf);
    axes(handles.procesada);
    imshow(im2);
end
if modo == 3
    im = im2bw(im);
    axes(handles.procesada);
    imshow(im);
end
if modo == 4
    if length(size(im)) == 3
        im = rgb2gray(im);
    end
        axes(handles.procesada);
        im2 = medfilt2(im);
        imshow(im2);
end
if modo == 5
    set(handles.pushbutton1,'Enable','on');
end

% --- Executes when selected object is changed in uibuttongroup1.
function uibuttongroup1_SelectionChangedFcn(hObject, eventdata, handles)
% hObject    handle to the selected object in uibuttongroup1 
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
global modo;
if hObject == handles.radiobutton1
    modo = 1;
end
if hObject == handles.radiobutton2
    modo = 2;
end
if hObject == handles.radiobutton3
    modo = 3;
end
if hObject == handles.radiobutton4
    modo = 4;
end
if hObject == handles.radiobutton5
    modo = 5;
end


% --- Executes on button press in radiobutton2.
function radiobutton1_Callback(hObject, eventdata, handles)
% hObject    handle to radiobutton2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of radiobutton2

% --- Executes on button press in radiobutton2.
function radiobutton2_Callback(hObject, eventdata, handles)
% hObject    handle to radiobutton2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of radiobutton2

% doc imfilter