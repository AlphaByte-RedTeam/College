unit PisahWarnaPCD;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, ExtCtrls, StdCtrls;

type

  { TForm1 }

  TForm1 = class(TForm)
    btnLoad: TButton;
    btnSave: TButton;
    btnSplit: TButton;
    btnClose: TButton;
    imgRed: TImage;
    imgGreen: TImage;
    imgBlue: TImage;
    imgOriginal: TImage;
    openDialog: TOpenDialog;
    saveDialog: TSaveDialog;
    procedure btnCloseClick(Sender: TObject);
    procedure btnLoadClick(Sender: TObject);
    procedure btnSplitClick(Sender: TObject);
    // procedure imgOriginalClick(Sender: TObject);
    // procedure imgRedClick(Sender: TObject);
  private

  public

  end;

var
  Form1: TForm1;

implementation

{$R *.lfm}

{ TForm1 }

uses Windows;

// Global Variable Declaration
var
  bmpR, bmpG, bmpB : array[0..1000, 0..1000] of integer;

procedure TForm1.btnLoadClick(Sender: TObject);
begin
  if (openDialog.Execute) then
  begin
    imgOriginal.Picture.LoadFromFile(openDialog.FileName);
  end;
end;

procedure TForm1.btnCloseClick(Sender: TObject);
begin
  Close;
end;

procedure TForm1.btnSplitClick(Sender: TObject);
// Locale Variable Declaration in Procedure
var
  i, j : integer;
  Red, Green, Blue : integer;
begin
  begin
    for j:=0 to imgOriginal.Height do
    begin
      for i:=0 to imgOriginal.Width do
      begin
        Red := getRValue(imgOriginal.Canvas.Pixels[i, j]);
        Green := getGValue(imgOriginal.Canvas.Pixels[i, j]);
        Blue := getBValue(imgOriginal.Canvas.Pixels[i, j]);

        imgRed.Canvas.Pixels[i, j] := RGB(Red, 0, 0);
        imgGreen.Canvas.Pixels[i, j] := RGB(0, Green, 0);
        imgBlue.Canvas.Pixels[i, j] := RGB(0, 0, Blue);
      end;
    end;
  end;
end;

procedure TForm1.imgOriginalClick(Sender: TObject);
begin

end;

procedure TForm1.imgRedClick(Sender: TObject);
begin

end;

end.

