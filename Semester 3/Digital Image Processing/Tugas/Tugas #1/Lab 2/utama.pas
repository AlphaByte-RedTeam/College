unit Utama;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, StdCtrls, ExtCtrls,
  ComCtrls;

type

  { TFormUtama }

  TFormUtama = class(TForm)
    btnLoad: TButton;
    btnSave: TButton;
    btnRed: TButton;
    btnGreen: TButton;
    btnBlue: TButton;
    btnGray: TButton;
    btnBiner: TButton;
    imgOriginal: TImage;
    openDialog: TOpenDialog;
    saveDialog: TSaveDialog;
    trackBar: TTrackBar;
    procedure btnBinerClick(Sender: TObject);
    procedure btnBlueClick(Sender: TObject);
    procedure btnGrayClick(Sender: TObject);
    procedure btnGreenClick(Sender: TObject);
    procedure btnLoadClick(Sender: TObject);
    procedure btnRedClick(Sender: TObject);
    procedure btnSaveClick(Sender: TObject);
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
  bmpBiner : array[0..1000, 0..1000] of boolean;

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
      // Jika Pixel Green <= posisi trackBar
      if (bmpG[x, y] <= trackBar.Position) then
      begin
        // Maka image akan di set menjadi hitam
        imgOriginal.Canvas.Pixels[x, y] := RGB(0, 0, 0);
      end

      // Jika pixel Green > posisi trackBar
      else
      begin
        // Maka image akan di set menjadi Green
        imgOriginal.Canvas.Pixels[x, y] := RGB(0, 255, 0);
      end;
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
      // Jika Pixel Blue <= posisi trackBar
      if (bmpB[x, y] <= trackBar.Position) then
      begin
        // Maka image akan di set menjadi hitam
        imgOriginal.Canvas.Pixels[x, y] := RGB(0, 0, 0)
      end

      // Jika pixel Blue > posisi trackBar
      else
      begin
        // Maka image akan di set menjadi Blue
        imgOriginal.Canvas.Pixels[x, y] := RGB(0, 0, 255);
      end;
    end;
  end;
end;

procedure TFormUtama.btnBinerClick(Sender: TObject);
var
  x, y : integer;
  gray : byte;
begin
  for y:=0 to imgOriginal.Height-1 do
  begin
    for x:=0 to imgOriginal.Width-1 do
    begin
      // Algoritma grayscale value
      gray := (bmpR[x, y] + bmpG[x, y] + bmpB[x, y]) div 3;
      // Jika nilai grayscale <= posisi trackBar
      if (gray <= trackBar.Position) then
      begin
        // Maka image akan di set menjadi black
        imgOriginal.Canvas.Pixels[x, y] := RGB(0, 0, 0);
      end

      // Jika nilai grayscale > posisi trackBar
      else
      begin
        // Maka image akan di set menjadi white
        imgOriginal.Canvas.Pixels[x, y] := RGB(255, 255, 255);
      end;
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
      // Algoritma grayscale value
      gray := (bmpR[x, y] + bmpG[x, y] + bmpB[x, y]) div 3;
      // Jika nilai grayscale <= posisi trackbar
      if (gray <= trackBar.Position) then
      begin
        // Maka image akan di set menjadi hitam
        imgOriginal.Canvas.Pixels[x, y] := RGB(0, 0, 0);
      end

      // Jika nilai grayscale > posisi trackBar
      else
      begin
        // Maka image akan di set menjadi gray
        imgOriginal.Canvas.Pixels[x, y] := RGB(gray, gray, gray);
      end;
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
      if (bmpR[x, y] <= trackBar.Position) then
      begin
        imgOriginal.Canvas.Pixels[x, y] := RGB(0, 0, 0);
      end

      else
      begin
        imgOriginal.Canvas.Pixels[x, y] := RGB(255, 0, 0);
      end;
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

end.

