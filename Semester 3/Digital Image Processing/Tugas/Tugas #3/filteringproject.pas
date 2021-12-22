unit FilteringProject;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, StdCtrls, ExtCtrls;

type

  { TFilteringForm }

  TFilteringForm = class(TForm)
    btnLoad: TButton;
    btnSave: TButton;
    btnCorrelation: TButton;
    btnConvolution: TButton;
    imgOriginal: TImage;
    imgMod: TImage;
    lblImageMod: TLabel;
    lblImageOri: TLabel;
    openDialog: TOpenDialog;
    radioGroupColor: TRadioGroup;
    radioGroupFilter: TRadioGroup;
    saveDialog: TSaveDialog;
    procedure btnLoadClick(Sender: TObject);
  private

  public

  end;

var
  FilteringForm: TFilteringForm;

implementation

{$R *.lfm}

{ TFilteringForm }

uses Windows;

var
  bmpR, bmpG, bmpB, bmpGray: array[0..1000, 0..1000] of byte;
  __initWidth__, __initHeight__: integer;

procedure TFilteringForm.btnLoadClick(Sender: TObject);
var
  x, y: integer;
  gray: byte;
begin
  if openDialog.Execute then
  begin
    imgOriginal.Picture.LoadFromFile(openDialog.FileName);

    __initWidth__ := imgOriginal.Width;
    __initHeight__ := imgOriginal.Height;

    for y:=0 to imgOriginal.Height-1 do
    begin
      for x:=0 to imgOriginal.Width-1 do
      begin
        bmpR[x,y] := getRValue(imgOriginal.Canvas.Pixels[x,y]);
        bmpG[x,y] := getGValue(imgOriginal.Canvas.Pixels[x,y]);
        bmpB[x,y] := getBValue(imgOriginal.Canvas.Pixels[x,y]);

        gray := (bmpR[x,y] + bmpG[x,y] + bmpB[x,y]) div 3;
        bmpGray[x,y] := gray;
      end;
    end;
  end;
end;

end.

