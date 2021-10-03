unit Utama;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, StdCtrls, ExtCtrls;

type

  { TFormUtama }

  TFormUtama = class(TForm)
    btnLoad: TButton;
    btnWarna: TButton;
    btnRed: TButton;
    btnGreen: TButton;
    btnBlue: TButton;
    btnGray: TButton;
    btnSave: TButton;
    imgOriginal: TImage;
    openDialog: TOpenDialog;
    saveDialog: TSaveDialog;
    procedure btnBlueClick(Sender: TObject);
    procedure btnGrayClick(Sender: TObject);
    procedure btnGreenClick(Sender: TObject);
    procedure btnLoadClick(Sender: TObject);
    procedure btnRedClick(Sender: TObject);
    procedure btnSaveClick(Sender: TObject);
    procedure btnWarnaClick(Sender: TObject);
    procedure FormClick(Sender: TObject);
  private

  public

  end;

var
  FormUtama: TFormUtama;

implementation

{$R *.lfm}


{ TFormUtama }

uses Windows;

var
  bmpR, bmpG, bmpB : array[0..1000, 0..1000] of byte;

procedure TFormUtama.btnLoadClick(Sender: TObject);
var
  x, y : integer;
begin
  if openDialog.Execute then
  begin
    imgOriginal.Picture.LoadFromFile(openDialog.FileName);
    for y:=0 to imgOriginal.Height-1 do
    begin
      for x:=0 to imgOriginal.Width-1 do
      begin
        bmpR[x, y] := getRValue(imgOriginal.Canvas.Pixels[x, y]);
        bmpG[x, y] := getGValue(imgOriginal.Canvas.Pixels[x, y]);
        bmpB[x, y] := getBValue(imgOriginal.Canvas.Pixels[x, y]);
      end;
    end;
  end;
end;

procedure TFormUtama.btnGreenClick(Sender: TObject);
var
  x, y : integer;
begin
  for y:=0 to imgOriginal.Height-1 do
  begin
    for x:=0 to imgOriginal.Width-1 do
    begin
      imgOriginal.Canvas.Pixels[x, y] := RGB(0, bmpG[x, y], 0);
    end;
  end;
end;

procedure TFormUtama.btnBlueClick(Sender: TObject);
var
  x, y : integer;
begin
  for y:=0 to imgOriginal.Height-1 do
  begin
    for x:=0 to imgOriginal.Width-1 do
    begin
      imgOriginal.Canvas.Pixels[x, y] := RGB(0, 0, bmpB[x, y]);
    end;
  end;
end;

procedure TFormUtama.btnGrayClick(Sender: TObject);
var
  x, y : integer;
  gray : byte;
begin
  for y:=0 to imgOriginal.Height-1 do
  begin
    for x:=0 to imgOriginal.Width-1 do
    begin
      gray := (bmpR[x, y] + bmpG[x, y] + bmpB[x, y]) div 3;
      imgOriginal.Canvas.Pixels[x, y] := RGB(gray, gray, gray);
    end;
  end;
end;

procedure TFormUtama.btnRedClick(Sender: TObject);
var
  x, y : integer;
begin
  for y:=0 to imgOriginal.Height-1 do
  begin
    for x:=0 to imgOriginal.Width-1 do
    begin
      imgOriginal.Canvas.Pixels[x, y] := RGB(bmpR[x, y], 0, 0);
    end;
  end;
end;

procedure TFormUtama.btnSaveClick(Sender: TObject);
begin
  if saveDialog.Execute then
  begin
    imgOriginal.Picture.SaveToFile(saveDialog.FileName);
  end;
end;

procedure TFormUtama.btnWarnaClick(Sender: TObject);
var
  x, y : integer;
begin
  for y:=0 to imgOriginal.Height-1 do
  begin
    for x:=0 to imgOriginal.Width-1 do
    begin
      imgOriginal.Canvas.Pixels[x, y] := RGB(bmpR[x, y], bmpG[x, y], bmpB[x, y]);
    end;
  end;
end;

procedure TFormUtama.FormClick(Sender: TObject);
begin

end;

end.

