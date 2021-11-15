unit Unit1;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, StdCtrls, ExtCtrls,
  Buttons;

type

  { ToperasiAritmatika }

  ToperasiAritmatika = class(TForm)
    btnLoadA: TButton;
    btnSave: TButton;
    btnPenjumlahan: TButton;
    btnAND: TButton;
    btnLoadB: TButton;
    imgC: TImage;
    imgB: TImage;
    imgA: TImage;
    OpenDialog: TOpenDialog;
    SaveDialog: TSaveDialog;
    bitmapA: TStaticText;
    bitmapB: TStaticText;
    bitmapC: TStaticText;
    procedure btnANDClick(Sender: TObject);
    procedure btnLoadAClick(Sender: TObject);
    procedure btnLoadBClick(Sender: TObject);
    procedure btnPenjumlahanClick(Sender: TObject);
    procedure btnSaveClick(Sender: TObject);
  private

  public

  end;

var
  operasiAritmatika: ToperasiAritmatika;

implementation

{$R *.lfm}

{ ToperasiAritmatika }

uses Windows;

var
  bmpR, bmpG, bmpB: array[0..1000, 0..1000] of byte;
  imgA, imgB, imgC: array[0..1000, 0..1000] of byte;

procedure ToperasiAritmatika.btnSaveClick(Sender: TObject);
begin
  if SaveDialog.Execute then
  begin
    imgC.Picture.SaveToFile(SaveDialog.FileName);
  end;
end;

procedure ToperasiAritmatika.btnLoadAClick(Sender: TObject);
var
  x, y: integer;

begin
  if OpenDialog.Execute then
  begin
    imgA.Picture.LoadFromFile(OpenDialog.FileName);
    for y:=0 to imgA.Height-1 do
    begin
      for x:=0 to imgA.Width-1 do
      begin
        bmpR[x, y] := getRValue(imgA.Canvas.Pixels[x, y]);
        bmpG[x, y] := getGValue(imgA.Canvas.Pixels[x, y]);
        bmpB[x, y] := getBValue(imgA.Canvas.Pixels[x, y]);
      end;
    end;
  end;
end;

procedure ToperasiAritmatika.btnANDClick(Sender: TObject);
var
  x, y: integer;
begin
  for y:=0 to imgC.Height-1 do
  begin
    for x:=0 to imgC.Width-1 do
    begin
      imgC.Canvas.Pixels[x, y] := imgA.Canvas.Pixels[x, y] and imgB.Canvas.Pixels[x, y];
    end;
  end;
end;

procedure ToperasiAritmatika.btnLoadBClick(Sender: TObject);
var
  x, y: integer;

begin
  if OpenDialog.Execute then
  begin
    imgB.Picture.LoadFromFile(OpenDialog.FileName);
    for y:=0 to imgB.Height-1 do
    begin
      for x:=0 to imgB.Width-1 do
      begin
        bmpR[x, y] := getRValue(imgB.Canvas.Pixels[x, y]);
        bmpG[x, y] := getGValue(imgB.Canvas.Pixels[x, y]);
        bmpB[x, y] := getBValue(imgB.Canvas.Pixels[x, y]);
      end;
    end;
  end;
end;

procedure ToperasiAritmatika.btnPenjumlahanClick(Sender: TObject);
var
  x, y: integer;

begin
  for y:=0 to imgC.Height-1 do
  begin
    for x:=0 to imgC.Width-1 do
    begin
      imgC.Canvas.Pixels[x, y] := imgA.Canvas.Pixels[x, y] + imgB.Canvas.Pixels[x, y];
    end;
  end;
end;

end.

