// =============================================================
// (C) Copyright KerboGames(R), Germany 2020! All rights reserved!
// KESTD-Ronin                                                                    
// Mario
// ISerializable.hpp
// 30.08.2020 12:40
// =============================================================

#pragma once

namespace kestd
{
	class JSONSerializeStream;

	/// <summary>
	/// Base interface for all serializeable objects.
	/// </summary>
	class ISerializable
	{
	public:
		ISerializable() noexcept = default;
		ISerializable(const ISerializable&) noexcept = default;
		ISerializable(ISerializable&&) noexcept = default;
		ISerializable& operator=(const ISerializable&) noexcept = default;
		ISerializable& operator=(ISerializable&&) noexcept = default;
		virtual ~ISerializable() = default;

		virtual auto serialize(JSONSerializeStream& stream) -> bool = 0;
		virtual auto deserialize(JSONSerializeStream& stream) -> bool = 0;
	};
}
