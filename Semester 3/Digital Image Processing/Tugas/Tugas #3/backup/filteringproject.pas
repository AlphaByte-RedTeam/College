unit FilteringProject;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, StdCtrls, ExtCtrls;

type

  { TFilteringForm }

  TFilteringForm = class(TForm)
    editKernel: TEdit;
    imgSketch: TImage;
    lblKernelSize: TLabel;
    btnLoad: TButton;
    btnSave: TButton;
    btnCorrelation: TButton;
    btnConvolution: TButton;
    imgOri: TImage;
    imgMod: TImage;
    openDialog: TOpenDialog;
    radioFilterMode: TRadioGroup;
    radioColorMode: TRadioGroup;
    saveDialog: TSaveDialog;
    procedure btnConvolutionClick(Sender: TObject);
    procedure btnCorrelationClick(Sender: TObject);
    procedure btnLoadClick(Sender: TObject);
    procedure btnSaveClick(Sender: TObject);
  private
    function constrain(val: integer): byte;
    procedure initKernel();
    procedure padBitmap();

  public

  end;

var
  FilteringForm: TFilteringForm;

implementation

{$R *.lfm}

uses Windows;

var
  bmpR, bmpG, bmpB, bmpGray: array[0..1000, 0..1000] of byte;
  padR, padG, padB, padGray: array[0..1000, 0..1000] of double;
  kernelSize: array[0..100, 0..100] of double;
  __initWidth__, __initHeight__: integer;
  k, kHalf: integer;

{ TFilteringForm }

procedure TFilteringForm.btnLoadClick(Sender: TObject);
var
  x, y: integer;
begin
  if openDialog.Execute then
  begin
     imgOri.Picture.LoadFromFile(openDialog.FileName);
     __initHeight__ := imgOri.Height;
     __initWidth__ := imgOri.Width;

     for y:=0 to imgOri.Height-1 do
     begin
       for x:=0 to imgOri.Width-1 do
       begin
         bmpR[x,y] := Red(imgOri.Canvas.Pixels[x,y]);
         bmpG[x,y] := Green(imgOri.Canvas.Pixels[x,y]);
         bmpB[x,y] := Blue(imgOri.Canvas.Pixels[x,y]);

         bmpGray[x,y] := (bmpR[x,y] + bmpG[x,y] + bmpB[x,y]) div 3;
       end;
     end;
  end;
end;

procedure TFilteringForm.btnCorrelationClick(Sender: TObject);
var
  x, y, xK, yK: integer;
  cBR, cBG, cBB, cBGray: array[0..1000, 0..1000] of integer;
  cR, cG, cB, cGray: double;
begin
  imgMod.Width := __initWidth__;
  imgMod.Height := __initHeight__;
  k := StrToInt(editKernel.Text);
  kHalf := k div 2;
  initKernel();
  padBitmap();

  if radioColorMode.ItemIndex = 1 then
  begin
     for y:=kHalf to (__initHeight__ + kHalf) do
     begin
       for x:=kHalf to (__initWidth__ + kHalf) do
       begin
         cR := 0;
         cG := 0;
         cB := 0;

         for yK:=1 to k do
         begin
           for xK:=1 to k do
           begin
             cR := cR + (padR[x + (xK - k + kHalf), y + (yK - k + kHalf)] * kernelSize[xK, yK]);
             cG := cG + (padG[x + (xK - k + kHalf), y + (yK - k + kHalf)] * kernelSize[xK, yK]);
             cB := cB + (padB[x + (xK - k + kHalf), y + (yK - k + kHalf)] * kernelSize[xK, yK]);
           end;
         end;

         cBR[x - kHalf, y - kHalf] := constrain(Round(cR));
         cBG[x - kHalf, y - kHalf] := constrain(Round(cG));
         cBB[x - kHalf, y - kHalf] := constrain(Round(cB));
       end;
     end;

     for y:=0 to __initHeight__-1 do
     begin
       for x:=0 to __initWidth__-1 do
       begin
         imgMod.Canvas.Pixels[x,y] := RGB(cBR[x,y], cBG[x,y], cBB[x,y]);
       end;
     end;
  end
  else if radioColorMode.ItemIndex = 0 then
  begin
     for y:=kHalf to (__initHeight__+kHalf) do
     begin
       for x:=kHalf to (__initWidth__+kHalf) do
       begin
         cGray := 0;
         for yK:=1 to k do
         begin
           for xK:=1 to k do
           begin
             cGray := cGray + (padGray[x + (xK - k + kHalf), y + (yK - k + kHalf)] * kernelSize[xK, yK]);
           end;
         end;

         cBGray[x - kHalf, y - kHalf] := constrain(Round(cGray));
       end;
     end;

     for y:=0 to __initHeight__-1 do
     begin
       for x:=0 to __initWidth__-1 do
       begin
         imgMod.Canvas.Pixels[x,y] := RGB(cBGray[x,y], cBGray[x,y], cBGray[x,y]);

         if radioFilterMode.ItemIndex <> 2 then
            imgSketch.Canvas.Pixels[x,y] := RGB(255-cBGray[x,y], 255-cBGray[x,y], 255-cBGray[x,y]);
       end;
     end;
  end;
end;

procedure TFilteringForm.btnConvolutionClick(Sender: TObject);
var
  x, y, xK, yK: integer;
  cBR, cBG, cBB, cBGray: array[0..1000, 0..1000] of integer;
  cR, cG, cB, cGray: double;
begin
  imgMod.Height := __initHeight__;
  imgMod.Width := __initWidth__;

  imgSketch.Height := __initHeight__;
  imgSketch.Width := __initWidth__;

  k := StrToInt(editKernel.Text);
  kHalf := k div 2;
  initKernel();
  padBitmap();

  if radioColorMode.ItemIndex = 1 then
  begin
     for y:=kHalf to (__initHeight__+kHalf) do
     begin
       for x:=kHalf to (__initWidth__+kHalf) do
       begin
         cR := 0;
         cG := 0;
         cB := 0;

         for yK:=1 to k do
         begin
           for xK:=1 to k do
           begin
             cR := cR + (padR[x - (xK - k + kHalf), y - (yK - k + kHalf)] * kernelSize[xK, yK]);
             cG := cG + (padG[x - (xK - k + kHalf), y - (yK - k + kHalf)] * kernelSize[xK, yK]);
             cB := cB + (padB[x - (xK - k + kHalf), y - (yK - k + kHalf)] * kernelSize[xK, yK]);
           end;
         end;

         cBR[x - kHalf, y - kHalf] := constrain(Round(cR));
         cBG[x - kHalf, y - kHalf] := constrain(Round(cG));
         cBB[x - kHalf, y - kHalf] := constrain(Round(cB));
       end;
     end;

     for y:= 0 to __initHeight__-1 do
     begin
       for x:=0 to __initWidth__-1 do
       begin
         imgMod.Canvas.Pixels[x,y] := RGB(cBR[x,y], cBG[x,y], cBB[x,y]);
       end;
     end;
  end

  else if radioColorMode.ItemIndex = 0 then
  begin
     for y:=kHalf to (__initHeight__+kHalf) do
     begin
       for x:=kHalf to (__initWidth__+kHalf) do
       begin
         cGray := 0;
         for yK:=1 to k do
         begin
           for xK:=1 to k do
           begin
             cGray := cGray + (padGray[x - (xK - k + kHalf), y - (yK - k + kHalf)] * kernelSize[xK, yK]);
           end;
         end;

         cBGray[x - kHalf, y - kHalf] := constrain(Round(cGray));
       end;
     end;

     for y:=0 to __initHeight__-1 do
     begin
       for x:= to __initWidth__-1 do
       begin
         imgMod.Canvas.Pixels[x,y] := RGB(cBGray[x,y], cBGray[x,y], cBGray[x,y]);

         if radioFilterMode.ItemIndex <> 2 then
            imgSketch.Canvas.Pixels[x,y] := RGB(255 - cBGray[x,y], 255 - cBGray[x,y], 255 - cBGray[x,y]);
       end;
     end;
  end;
end;

procedure TFilteringForm.btnSaveClick(Sender: TObject);
begin
  if saveDialog.Execute then
     imgMod.Picture.SaveToFile(saveDialog.FileName);
end;

function TFilteringForm.constrain(val: integer): byte;
begin
  if val < 0 then
  begin
     constrain := 0;
  end
  else if val > 255 then
  begin
     constrain := 255;
  end
  else
      constrain := val;
end;

procedure TFilteringForm.initKernel();
var
  x, y: integer;
begin
  if radioFilterMode.ItemIndex = 2 then
  begin
     for y:=1 to k do
     begin
       for x:=1 to k do
       begin
         kernelSize[x,y] := 1 / (k*k);
       end;
     end;
  end

  else
  begin
    for y:=1 to k do
    begin
      for x:=1 to k do
      begin
        kernelSize[x,y] := -1;
      end;
    end;
    if radioFilterMode.ItemIndex = 1 then
    begin
       kernelSize[kHalf,kHalf] := (k*k);
    end
    else if radioFilterMode.ItemIndex = 0 then
    begin
       kernelSize[kHalf,kHalf] := (k*k) - 1;
    end;
  end;
end;

procedure TFilteringForm.padBitmap();
var
  x, y, z: integer;
begin
  if radioColorMode.ItemIndex = 1 then
  begin
     for y:=0 to __initHeight__+kHalf do
     begin
       for z:=0 to kHalf-1 do
       begin
         padR[0+z, y] := 255;
         padR[__initWidth__+kHalf+z, y] := 255;

         padG[0+z, y] := 255;
         padG[__initWidth__+kHalf+z, y] := 255;

         padB[0+z, y] := 255;
         padB[__initWidth__+kHalf+z, y] := 255;
       end;
     end;

     for x:=0 to __initWidth__+kHalf do
     begin
       for z:=0 to kHalf-1 do
       begin
         padR[x, 0+z] := 255;
         padG[x, __initWidth__+kHalf+z] := 255;

         padG[x, 0+z] := 255;
         padG[x, __initWidth__+kHalf+z] := 255;

         padB[x, 0+z] := 255;
         padB[x, __initWidth__+kHalf+z] := 255;
       end;
     end;

     for y:=kHalf to (__initHeight__+kHalf-1) do
     begin
       for x:=kHalf to (__initWidth__+kHalf-1) do
       begin
         padR[x,y] := bmpR[x-kHalf, y-kHalf];
         padG[x,y] := bmpG[x-kHalf, y-kHalf];
         padB[x,y] := bmpB[x-kHalf, y-kHalf];
       end;
     end;
  end
  else if radioColorMode.ItemIndex=0 then
  begin
     for y:=0 to __initHeight__+kHalf do
     begin
       for z:=0 to kHalf-1 do
       begin
         padGray[0+z, y] := 255;
         padGray[__initWidth__+kHalf+z, y] := 255;
       end;
     end;

     for x:=0 to __initWidth__+kHalf do
     begin
       for z:=0 to kHalf-1 do
       begin
         padGray[x, 0+z] := 255;
         padGray[x, __initHeight__+kHalf+z] := 255;
       end;
     end;

     for y:=kHalf to (__initHeight__+kHalf-1) do
     begin
       for x:=kHalf to (__initWidth__+kHalf-1) do
       begin
         padGray[x,y] := bmpGray[x-kHalf, y-kHalf];
       end;
     end;
  end;
end;

end.

