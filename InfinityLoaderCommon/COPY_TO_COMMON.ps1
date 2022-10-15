
param (
	[Parameter(Mandatory)][string]$OutDir
)

try {
	New-Item -ItemType Directory -Force -Path "../common/include/" | Out-Null
	Copy-Item "Common Headers/*" "../common/include" -Recurse -Force
	Copy-Item "InfinityLoaderCommon.cpp" "../common/include" -Force
}
catch {
	Write-Output $_; Exit -1
}
