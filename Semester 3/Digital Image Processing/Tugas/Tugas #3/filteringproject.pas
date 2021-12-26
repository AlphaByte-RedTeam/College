unit FilteringProject;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, StdCtrls, ExtCtrls;

type

  { TFilteringForm }

  TFilteringForm = class(TForm)
    editKernel: TEdit;
    kernelSize: TLabel;
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
    procedure btnLoadClick(Sender: TObject);
    procedure btnSaveClick(Sender: TObject);
  private
    function constrain(val: integer): byte;

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
  kernel: array[0..100, 0..100] of double;
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

end.

