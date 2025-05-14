
param (
	[Parameter(Mandatory)][string]$OutDir,
	[Parameter(Mandatory)][string]$GamePath
)

try {
	if ($Env:DEPLOY -eq "1") {
		"LuaProvider.dll" | ForEach-Object {Copy-Item "$OutDir\$_" "$Env:DEPLOY_DIRECTORY\EEex\loader\LuaJIT\$_"}
		"LuaProvider.pdb" | ForEach-Object {Copy-Item "$OutDir\$_" "$Env:DEPLOY_DIRECTORY\pdb\LuaJIT\$_"}
	}
	if (($Env:USING_LUAJIT -eq "1") -and ($GamePath -ne ".") -and (Test-Path $GamePath)) {
		"LuaProvider.dll", "LuaProvider.pdb" | ForEach-Object {Copy-Item "$OutDir/$_" $GamePath}
	}
}
catch {
	Write-Output $_
	Exit -1
}
